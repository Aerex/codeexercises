function prune(arrA, arrB){
	var j = 0;
	   for(var i = 0; i < arrA.length; i++){
    	for(; j < arrB.length; j++){
      	if(!arrB[j]) continue;
      	if(arrA[i] == arrB[j]){
        	arrB[j] = undefined;
          break;
        }
      }
   }
   
   prunedArr = arrB.join("").split("");
   
   return prunedArr;
}

function isValid(first, second, third){
   var firstArr = first.split("");
   var secondArr = second.split("");
   var thirdArr = third.split("");
 

	thirdArr = prune(firstArr, thirdArr);
  
  thirdArr = prune(secondArr, thirdArr);
 
   
   return thirdArr.join("") === "" ? true : false;

}


console.log(isValid("abc", "def", "eabdfc")); // false
console.log(isValid("abc", "def", "dabefc")); //true