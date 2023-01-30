package com.dxfeed.api;

import com.dxfeed.event.market.TimeAndSale;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class JniTest {
    private static final Map<Long, DXFeedSubscription<TimeAndSale>> nativeSubToDxFeedSub = new HashMap<>();

    private static long createSubscription() {
        System.load("/Users/Andrey.Mikhalev/Documents/work/graal-native-test/native/jni-lib/bin/native_jni.dylib");
        DXEndpoint endpoint = DXEndpoint.newBuilder()
                .build()
                .connect("demo.dxfeed.com:7300");
        DXFeed feed = endpoint.getFeed();
        final DXFeedSubscription<TimeAndSale> sub = feed.createSubscription(TimeAndSale.class);
        System.out.println("sub = " + sub);
        long l = nCreateDxFeedSubscription(sub);
        nativeSubToDxFeedSub.put(l, sub);
        System.out.println("l = " + l);
        return l;
    }

    public static void main(String[] args) throws InterruptedException {
        createSubscription();
        Thread.sleep(10000);
    }


    // callback from native
    private static void addEventListener(long dxFeedSub, long userCallback) {
        System.out.println("addEventListener, dxFeedSub = " + dxFeedSub + "; userCallback = " + userCallback);
        DXFeedSubscription<TimeAndSale> sub = nativeSubToDxFeedSub.get(dxFeedSub);
        System.out.println("addEventListener, sub = " + sub);
        sub.addEventListener(eventList -> nOnQuoteEventListener(dxFeedSub, eventList.size(), eventList, userCallback));
        sub.addSymbols("ETH/USD:GDAX");
    }

    private static native long nCreateDxFeedSubscription(DXFeedSubscription<?> subscription);
    private static native void nOnQuoteEventListener(long dxFeedSub, int size, List<?> eventList, long userCallback);
}
