/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const resArr = [];
    arr.forEach((ele, ind) => {
        resArr[ind] = fn(ele, ind);
    });

    return resArr;
};