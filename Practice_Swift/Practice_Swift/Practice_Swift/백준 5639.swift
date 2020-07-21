//
//  main.swift
//  Practice_Swift
//
//  Created by 김성헌 on 2020/07/21.
//  Copyright © 2020 김성헌. All rights reserved.
//

import Foundation

class TreeNode{
    var value:Int = 0
    var left:TreeNode? = nil
    var right:TreeNode? = nil
    
    init(num:Int) {
        value = num
    }
    
    func insert(val:Int){
        if(value > val){
            if left  == nil{
                left = TreeNode(num: val)
            }
            else{
                left?.insert(val: val)
            }
        }else{
            if right == nil{
                right = TreeNode(num: val)
            }else{
                right?.insert(val: val)
            }
        }
        return
    }
}
func postorder(root:TreeNode){
    if root.left != nil{
        postorder(root: root.left!)
    }
    if root.right != nil{
        postorder(root: root.right!)
    }
    print(root.value)
}
var index = 0;
var root:TreeNode? = nil

while let line = readLine() {
    let str = line
    if(index == 0){
        root = TreeNode(num: Int(str)!)
    }else{
        root!.insert(val: Int(str)!)
    }
    index+=1
}
postorder(root: root!)
