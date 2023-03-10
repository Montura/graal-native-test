package com.dxfeed.api;

import com.dxfeed.event.market.TimeAndSale;

import java.nio.charset.StandardCharsets;
import java.util.List;

public class JniTest {

    private static class TimeAndSalesNative {
        // 3000 quotes -> max
        private final int totalBytes = 46 * 2000;
        private final int totalDoubleBytes = 24 * 2000;
        private final byte[] pByteData = new byte[totalBytes];
        private final double[] pDobuleData = new double[totalDoubleBytes];

        private static int writeBytes(byte[] data, int pos, byte[] value) {
            System.arraycopy(value, 0, data, pos, value.length);
            return pos + value.length;
        }

        private static int writeString(byte[] data, int pos, String value) {
            boolean isValidStr = value != null;
            byte length = isValidStr ? (byte) value.length() : 0;
            pos = writeByte(data, pos, length);
            pos = isValidStr ? writeBytes(data, pos, value.getBytes(StandardCharsets.UTF_8)) : 0;
            return pos;
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

        private static int writeDouble(double[] data, int pos, double value) {
            data[pos++] = value;
            return pos;
        }


        TimeAndSalesNative(List<TimeAndSale> quoteList) {
            int quoteCount = quoteList.size();
            int pos = 0;
            for (int i = 0; i < quoteCount; ++i) {
                TimeAndSale quote = quoteList.get(i);
                String eventSymbol = quote.getEventSymbol();
                long eventTime = quote.getEventTime();                                   // 8
                long index = quote.getIndex();                                           // 8
                int event_flags = quote.getEventFlags();                                 // 4
                int time_nano_part = quote.getTimeNanoPart();                            // 4
                byte exchange_code = (byte) quote.getExchangeCode();                     // 1
                long quoteSize = quote.getSize();                                        // 8

                String exchangeSaleConditions = quote.getExchangeSaleConditions();
                String buyer = quote.getBuyer();
                String seller = quote.getSeller();

                pos = writeString(pByteData, pos, eventSymbol);             // 1 + eventSymbolLength
                pos = writeLong(pByteData, pos, eventTime);                 // 8
                pos = writeLong(pByteData, pos, index);                     // 8
                pos = writeInt(pByteData, pos, event_flags);                // 4
                pos = writeInt(pByteData, pos, time_nano_part);             // 4
                pos = writeByte(pByteData, pos, exchange_code);             // 1
                pos = writeLong(pByteData, pos, quoteSize);                 // 8
                pos = writeString(pByteData, pos, exchangeSaleConditions);  // 1 + exchangeSaleConditionsLength
                pos = writeString(pByteData, pos, buyer);                   // 1 +  buyerLength
                pos = writeString(pByteData, pos, seller);                  // 1 +  sellerLength
                pos = 0;

                // DOUBLE DATA
                double price = quote.getPrice();                                         // 8
                double bid_price = quote.getBidPrice();                                  // 8
                double ask_price = quote.getAskPrice();                                  // 8
                pos = writeDouble(pDobuleData, pos, price);
                pos = writeDouble(pDobuleData, pos, bid_price);
                pos = writeDouble(pDobuleData, pos, ask_price);
                pos = 0;
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
            TimeAndSalesNative nativeTS = new TimeAndSalesNative(eventList);
            nOnQuoteEventListener(eventList.size(), nativeTS.pByteData, nativeTS.pDobuleData, userCallback);
        });
    }

    private static native void nOnQuoteEventListener(int size, byte[] byteData, double[] doubleData, long userCallback);
}
