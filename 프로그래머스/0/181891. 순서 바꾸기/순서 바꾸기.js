function solution(num_list, n) {
    for(let i=0; i<n; i++){
        let j = num_list.shift();
        num_list.push(j);
    }
    return num_list;
}