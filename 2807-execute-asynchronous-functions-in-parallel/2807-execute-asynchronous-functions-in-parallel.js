/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {

    // track how many promises resolved
    let length = functions.length;

    // create & return main promise
    return new Promise((resolve, reject) => {
        
        // Array of resolved promises to return
        const res = new Array(length);

        // Execute each async function
        functions.forEach((fn, i) => {
            fn().then(value => {

                // set resolved value in the proper order
                res[i] = value;

                // track how many promises resolved
                --length;

                // if all resolved, resolve
                if (length === 0)
                    resolve(res);
            }).catch(err => {

                // any rejections should reject
                reject(err);
            });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */