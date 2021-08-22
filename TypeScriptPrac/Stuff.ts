function twoSum(nums: number[], target: number): number[] {
    const counter: Map<number, number> = new Map()
    let result: number[] = []
    
    for (var i = 0; i < nums.length; i++) {
        counter.set(target - nums[i], i)
    }
    
    for (var i = 0; i < nums.length; i++) {
        if (counter.get(nums[i])) {
            result.push(i)
            result.push(counter.get(nums[i]) as number)
            return result
        }
    }
    return [-1, -1]
};

function addTwoBinaries(binOne: string, binTwo: string) {
    let maxLength = Math.max(binOne.length, binTwo.length)
    console.log(maxLength)

    binOne = binOne.padStart(maxLength, '0')
    binTwo = binTwo.padStart(maxLength, '0')

    let result = ""
    let carry = false

    for (var i = maxLength - 1; -1 < i; i--) {
        if (binOne.charAt(i) === "1" && binTwo.charAt(i) === "1") {
            if (carry) {
                result += "1"
            } else {
                carry = true
                result += "0"
            }
        } else if(binOne.charAt(i) === "1" || binTwo.charAt(i) === "1") {
            if (carry) {
                result += "0"
            } else {
                result += "1"
            }
        } else {
            if (carry) {
                result += "1"
            } else {
                result += "0"
            }
            carry = false
        }
    }

    if (carry) {
        result += "1"
    }

    return result.split("").reverse().join("")
}

class Person {

    public firstName: string;
    public lastName: string;

    constructor (firstName = "None", lastName = "None") {
        this.firstName = firstName;    
        this.lastName = lastName
    }
}

// console.log(twoSum([2,7,11,15], 9))
// console.log(twoSum([3,2,4], 6))
// console.log(twoSum([3,2,4], 6))

console.log(addTwoBinaries("11", "1"))
console.log(addTwoBinaries("1010", "1011"))

var somePerson = new Person("Joe", "Stratam")
console.log(somePerson.firstName)
console.log(somePerson.lastName)