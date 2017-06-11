process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var s = readLine();
    var t = readLine();
    var k = parseInt(readLine());

    // case 1

    if(s.length + t.length <= k){
        console.log("Yes");
    } else{
            // keep iterating until we reach different character
        var commonLength = 0;
        while(commonLength < s.length && commonLength < t.length && s[commonLength] == t[commonLength]){
            commonLength++;
        }

        var diff = s.length + t.length - 2*commonLength;
    //
        if(diff <= k && diff%2 === k%2){
            console.log("Yes");
        } else {
            console.log("No");
        }

    }

}
