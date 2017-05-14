function replace(word, len){
  var newword = "";
   for(var i = 0 ; i < len; i++){
      if(word[i] === " "){
        newword+="%20";
      } else {
        newword+=word[i];
      }
    
   }
   
   return newword;
}


console.log(replace("Mr John Smith     ",13));
