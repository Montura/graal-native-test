package com.dxfeed.api;

import com.dxfeed.event.market.TimeAndSale;

import java.nio.charset.StandardCharsets;
import java.util.List;

public class JniTest {

    private static class TimeAndSalesNative {
        private final int totalBytes = 46 * 3000;
        private final byte[] pBytes = new byte[totalBytes];

        private static int writeBytes(byte[] data, int pos, byte[] value) {
            System.arraycopy(value, 0, data, pos, value.length);
            return pos + value.length;
        }

        private static int writeByte(byte[] data, int pos, byte value) {
            data[pos] = value;
            ++pos;
            return pos;
        }

        private static int writeInt(byte[] data, int pos, int value) {
            data[pos++] = (byte) value;
            data[pos++] = (byte) (value >> 8);
            data[pos++] = (byte) (value >> 16);
            data[pos++] = (byte) (value >> 24);
            return pos;
        }

        private static int writeLong(byte[] data, int pos, long value) {
            for (int i = 0; i < 8; i++) {
                data[pos++] = (byte) value;
                value = value >> 8;
            }
            return pos;
        }

        TimeAndSalesNative(List<TimeAndSale> quoteList) {
            int size = quoteList.size();
            int pos = 0;
            for (int i = 0; i < size; ++i) {
                TimeAndSale quote = quoteList.get(i);
                String eventSymbol = quote.getEventSymbol();
                byte eventSymbolLength = (byte) eventSymbol.length();
                long eventTime = quote.getEventTime();                                   // 8
                long index = quote.getIndex();                                           // 8
                int event_flags = quote.getEventFlags();                                 // 4
                int time_nano_part = quote.getTimeNanoPart();                           // 4
                byte exchange_code = (byte) quote.getExchangeCode();

                pos = writeByte(pBytes, pos, eventSymbolLength);
                pos = writeBytes(pBytes, pos, eventSymbol.getBytes(StandardCharsets.UTF_8));
                pos = writeLong(pBytes, pos, eventTime);
                pos = writeLong(pBytes, pos, index);
                pos = writeInt(pBytes, pos, event_flags);
                pos = writeInt(pBytes, pos, time_nano_part);
                pos = writeByte(pBytes, pos, exchange_code);
            }
        }
    }

    private static long createSubscription() {
//        System.load("/Users/Andrey.Mikhalev/Documents/work/graal-native-test/native/jni-lib/bin/native_jni.dylib");
        DXEndpoint endpoint = DXEndpoint.newBuilder()
                .build()
                .connect("demo.dxfeed.com:7300");
        DXFeed feed = endpoint.getFeed();
        final DXFeedSubscription<TimeAndSale> sub = feed.createSubscription(TimeAndSale.class);
        return 0;
    }

    public static void main(String[] args) throws InterruptedException {
        createSubscription();
        Thread.sleep(10000);
    }

    // callback from native
    private static void addEventListener(DXFeedSubscription<TimeAndSale> sub, long userCallback) {
        System.out.println("addEventListener, dxFeedSub = " + sub + "; userCallback = " + userCallback);

        sub.addEventListener(eventList -> {
            TimeAndSalesNative timeAndSalesNative = new TimeAndSalesNative(eventList);
            nOnQuoteEventListener(eventList.size(), timeAndSalesNative.pBytes, userCallback);
        });
    }

    private static native void nOnQuoteEventListener(int size, byte[] eventList, long userCallback);
}
