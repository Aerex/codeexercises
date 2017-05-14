function Node(value){
    this.left = null;
    this.right = null;
    this.data = value;
}


Node.prototype.insert = function(value){
    var current = this;
    var parent = null;
    var newNode = new Node(value);

    while(1) {
        parent = current;

        if(current.data > value) {
            current = current.left;
            if(!current) {
                parent.left = newNode;
                return;
            }
        } else {
                current = current.right;
                if(!current){
                    parent.right = newNode;
                    return;
                }
            }
    }
};

Node.prototype.find = function(value){
    var current = this;
debugger;
    while(current != null){
        if(value < current.data){ // if value is smaller go to the right
            current = current.left;
        } else if(value > current.data){ // if value is greater go to the left
            current = current.right;
        } else {
            return true;
        }
    }

    return false;
};

function _getSuccessor(deleteNode){
    var current = deleteNode.right;
    var parent = null;
    var successor = null;
    //find the smallest node
    while(current!=null){
        parent = successor;
        successor = current;
        current = current.left;
    }

    //make new parent left to be the successor right
    parent.left = successor.right;


    return successor;
}

Node.prototype.delete = function(value){

    var current = this;
    var parent = null;
    var isLeft = false;

    while(current.data != value){
        parent = current;

        if(value > current.data){
            current = current.right;
            isLeft = false;
        } else if(value < current.data) {
            current = current.left;
            isLeft = true;
        } else {
            return false;
        }

    }

    // Case 1: If no leaf children

    if(current.left == null && current.right == null){
        if(isLeft){
            parent.left = null;
        } else {
            parent.right = null;
        }
    }

    //Case 2: If one child remains
    else if(current.left == null){
        if(isLeft){
            parent.left = current.right;
        } else {
            parent.right = current.right;
        }

    }

    else if(current.right == null){
        if(isLeft){
            parent.left = current.left;
        } else {
            parent.right = current.left;
        }
    }

    // Case 3: Use successor
    else if(current.left !== null && current.right !== null) {
            var successor = _getSuccessor(current);
            if(isLeft){
                parent.left = successor;
            } else{
                parent.right = successor;
            }

            successor.left = current.left;
            successor.right = current.right;
    }

    return true;
}


var root = new Node(20);
root.insert(15);
root.insert(25);
root.insert(10);
root.insert(18);
root.insert(12);
root.insert(17);
root.insert(19);
root.insert(16);

root.delete(15);

console.log('ok');



