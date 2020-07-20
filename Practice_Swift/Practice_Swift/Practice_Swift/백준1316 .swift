//
//  main.swift
//  Practice_Swift
//
//  Created by 김성헌 on 2020/07/20.
//  Copyright © 2020 김성헌. All rights reserved.
//

import Foundation

var num = readLine()
var ans = 0;
for _ in 0...Int(num!)!-1{
    let str = readLine()!
    var set = Set<Character>()
    var pre = str.first!
    var check = false;
    for j in 0...str.count-1{
        if set.contains(str[str.index(str.startIndex, offsetBy: j)]) && pre != str[str.index(str.startIndex, offsetBy: j)]{
            check = true;
            break;
        }
        set.insert(str[str.index(str.startIndex, offsetBy: j)])
        pre = str[str.index(str.startIndex, offsetBy: j)]
    }
    if !check{
        ans += 1
    }
}
print(ans)
