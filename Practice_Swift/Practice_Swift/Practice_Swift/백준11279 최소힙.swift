struct heap{
    var arr = [Int]()
    func count()->Int{
        return arr.count
    }
    mutating func push(x:Int){
        arr.append(x)
        var current = arr.count-1
        while(current > 0 && arr[(current-1)/2] > arr[current]){
            let parent = (current-1)/2
            let temp = arr[parent]
            arr[parent] = arr[current]
            arr[current] = temp
            current = parent
        }
    }
    mutating func pop()->Int?{
        var ret:Int
        if arr.count == 0{
            ret = 0
        }else{
            ret = arr.first!
            arr[0] = arr.last!
            arr.remove(at: arr.count - 1)
            var current = 0
            while(true){
                let left = current * 2 + 1
                let right = current * 2 + 2
                if left >= arr.count{ //자식이 없으면 끝냄
                    break;
                }
                var next = current //
                if arr[next] > arr[left]{
                    next = left
                }
                if right<arr.count && arr[next] > arr[right]{
                    next = right
                }
                if next == current{ //어디로든 못가면 break
                    break;
                }
                let temp = arr[current]
                arr[current] = arr[next]
                arr[next] = temp
                current = next;
            }
        }
        return ret;
    }
}

var n = readLine()!
var min_heap = heap()
for _ in 0...Int(n)!-1{
//    if min_heap.arr.count > 0{
//        print(min_heap.arr[0])
//    }
    let element = readLine()!
    if Int(element)! == 0{
        print(min_heap.pop()!)
    }else{
        min_heap.push(x: Int(element)!)
    }
}
