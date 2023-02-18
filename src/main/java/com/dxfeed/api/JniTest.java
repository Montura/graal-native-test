package com.dxfeed.api;

import com.dxfeed.event.market.TimeAndSale;

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

    // callback from native
    private static <E> void addEventListener(DXFeedSubscription<E> sub, long userCallback) {
        System.out.println("addEventListener, dxFeedSub = " + sub + "; userCallback = " + userCallback);
        sub.addEventListener(eventList -> nOnQuoteEventListener(eventList.size(), eventList, userCallback));
    }

    private static native void nOnQuoteEventListener(int size, List<?> eventList, long userCallback);
}
