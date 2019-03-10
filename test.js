function solution(nums, n){
  const result = [];
  for(let i = 0; i < 2; i++){
    let tmp = [];
    tmp.push(i);
    result.push(tmp);
  }
  return result;
}
console.log(solution());
