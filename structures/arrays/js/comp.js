function comp(word){
    var compressedString = "";
    var prevChar = "";
    var repeat = 1;
    for(var i = 1; i < word.length+1; i++){
        if(word[i] === word[i-1]){
          repeat++;
        } else {
          compressedString+= (word[i-1] + repeat);
          repeat = 1;
        }
    }
    
    return compressedString
}

console.log(comp("aabbbccaad"))