package com.dxfeed.api;

import com.dxfeed.event.market.TimeAndSale;

import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.List;

public class JniTest {

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

    private static byte[] toNative(TimeAndSale quote) {
        String eventSymbol = quote.getEventSymbol();
        int eventSymbolLength = eventSymbol.length();
        long eventTime = quote.getEventTime();                                   // 8
        long index = quote.getIndex();                                           // 8
        int event_flags = quote.getEventFlags();                                 // 4
        long time_nano_part = quote.getTimeNanoPart();                           // 8
        char exchange_code = quote.getExchangeCode();                            // 2
        double price = quote.getPrice();                                         // 8
        double size = quote.getSize();                                           // 8
        double bid_price = quote.getBidPrice();                                  // 8
        double ask_price = quote.getAskPrice();                                  // 8
        String exchangeSaleConditions = quote.getExchangeSaleConditions();
//        int exchangeSaleConditionsLength = exchangeSaleConditions.length();      //
//        String buyer = quote.getBuyer();
//        int buyerLength = buyer.length();
//        String seller = quote.getSeller();
//        int sellerLength = seller.length();

        int totalSize = eventSymbolLength;// + 8 + 8 + 4 + 8 + 1 + 8 + 8 + 8 + 8 + exchangeSaleConditionsLength + buyerLength + sellerLength;
        ByteBuffer buffer = ByteBuffer.allocate(totalSize);
        buffer.put(eventSymbol.getBytes(StandardCharsets.UTF_8));

        return buffer.array();
    }

    // callback from native
    private static <E> void addEventListener(DXFeedSubscription<E> sub, long userCallback) {
        System.out.println("addEventListener, dxFeedSub = " + sub + "; userCallback = " + userCallback);

        sub.addEventListener(eventList -> {
            TimeAndSale[] timeAndSales = eventList.toArray(new TimeAndSale[0]);
            nOnQuoteEventListener(eventList.size(), timeAndSales, userCallback);
        });
    }

    private static native void nOnQuoteEventListener(int size, TimeAndSale[] eventList, long userCallback);
}
