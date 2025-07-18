function solution(my_string) {
    return my_string.split("").filter((word)=>!'aeiou'.includes(word)).join("");
}