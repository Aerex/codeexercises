function perm(a, b){
    var map = [];
   for(x in b){
      if(!map[b[x]]){
          map[b[x]] = 1;
      } else {
        map[b[x]]++;
      }     
   }
   
   for(x in a){
       if(!map[a[x]] || map[a[x]] == 0) return false;
       else map[a[x]]--;
   }
    return true;
}

console.log(perm("BALL", "LABL"));
console.log(perm("BALL", "LLBA"));