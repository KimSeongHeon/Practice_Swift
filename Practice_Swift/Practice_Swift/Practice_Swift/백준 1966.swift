//
//  main.swift
//  Practice_Swift
//
//  Created by 김성헌 on 2020/07/20.
//  Copyright © 2020 김성헌. All rights reserved.
//

import Foundation
public struct Queue<T>{
    internal var data = Array<T>()
    public init(){}
    public mutating func dequeue() -> T?{
        return data.removeFirst()
    }
    public func peek() -> T?{
        return data.first
    }
    public mutating func enqueue(element:T){
        data.append(element)
    }
    public mutating func clear(){
        data.removeAll()
    }
    public func count() -> Int{
        return data.count
    }
    public func isempty() -> Bool{
        return data.count == 0 ? true : false
    }
    public func getIndex(Index:Int)->T?{
        return data[data.index(data.startIndex, offsetBy: Index)]
    }
}
var arr  = [Int]();
var tc = readLine()!
for _ in 0...Int(tc)!-1{
    let nm = readLine()!
    let n = nm.components(separatedBy: " ")[0]
    let m = nm.components(separatedBy: " ")[1]
    let element = readLine()!.components(separatedBy: " ")
    var queue = Queue<(Int,Int)>()
    var index = 0;
    for item in element{
        queue.enqueue(element: (index,Int(item)!))
        index += 1
    }
    var ans = 0;
    while(!queue.isempty()){
        var check = false;
        for k in 0...queue.count()-1{
            if queue.peek()!.1 < queue.getIndex(Index: k)!.1{
                queue.enqueue(element: queue.dequeue()!)
                check = true;
                break;
            }
        }
        if !check{
            if queue.peek()!.0 == Int(m)!{
                arr.append(ans+1)
                break;
            }
            queue.dequeue()
            ans += 1;
        }
    }
}
for item in arr{
    print("\(item)")
}
