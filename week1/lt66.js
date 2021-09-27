/**
 * @param {number[]} digits
 * @return {number[]}
 */
 var plusOne = function(digits) {
    const len = digits.length;
    // 末尾为9加1 进位 : 上一位继续判断是否加1进位;
    for(let i = len - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] %= 10;
        // 末尾加1不进位 : 直接加后返回,
        if(digits[i]!=0) return digits;
    }
    // digits = [...Array(len + 1)].map(_=>0);
    // 上面写法不优雅 999类似情况
    digits = Array(len+1).fill(0);
    digits[0] = 1;
    return digits;
};

// let a = plusOne([9,9,9])
// console.log(a)
