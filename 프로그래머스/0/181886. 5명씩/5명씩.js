function solution(names) {
    var answers = [];
    for(let i=0;i<names.length;i+=5){
        answers.push(names[i]);
    }
    return answers;
}