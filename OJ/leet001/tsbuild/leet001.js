"use strict";
function twoSum(nums, target) {
    let M = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (M.has(target - nums[i])) {
            return [i, M.get(target - nums[i])];
        }
        M.set(nums[i], i);
    }
    return [];
}
;
console.log(twoSum([2, 7, 11, 15], 9));
//# sourceMappingURL=leet001.js.map