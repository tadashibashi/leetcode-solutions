class TreeNode {
    constructor() {
        if (arguments.length) {
            this.value = arguments[0];
            this.wasSet = true;
        } else {
            this.value = undefined;
            this.wasSet = false;
        }
        
        this.children = new Map();
    }

    /**
     * Ensures the inner value is set only once
     * Check for wasSet before setting
     * (Covers edge case where a memoized function returns undefined)
     */
    set(value) {
        this.wasSet = true;
        this.value = value;
    }
}

class MemoTree {
    constructor() {
        this.head = new TreeNode();
    }

    get(args, fn) {
        let cur = this.head, last = null;

        let i = 0;
        while (i < args.length) {

            last = cur;
            cur = cur.children.get(args[i]);

            if (!cur) {
                const newNode = new TreeNode();
                cur = newNode;
                last.children.set(args[i], newNode);
            }
            
            ++i;
        }

        if (!cur.wasSet)
            cur.set(fn(...args));
        return cur.value;
    }
}

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = new MemoTree();

    return function(...params) {
        return memo.get(params, fn);
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */