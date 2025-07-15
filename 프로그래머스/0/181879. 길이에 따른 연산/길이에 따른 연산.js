function solution(num_list) {
    let answer = (num_list.length >= 11) ? 0: 1;
    if(num_list.length>=11){
        for(i=0;i<num_list.length;i++){
            answer += num_list[i];
        }
    }else{
        for(i=0;i<num_list.length;i++){
            answer *= num_list[i];
        }
    }
    return answer;
}