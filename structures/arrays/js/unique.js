function unique(word){
   var map = [];
   var uniqueness = true;
	for(x in word){
  		if(!map[word[x]]){
      	 map[word[x]] = 1;
      } else {
      		uniqueness = false;
      }
  }
  
  return uniqueness;
}


console.log(unique("abc"));
console.log(unique("aabc"));
