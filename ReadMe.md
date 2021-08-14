# Sieve of Eratosthenes

Learning some basic C by implementing the Sieve of Eratosthenes wiki: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

Clojure:
```
(defn sieve 
  [^long limit]
  (let [limit-sqrt (-> limit Math/sqrt Math/round inc)]
    (loop [^longs numbers (range 2 limit)
           current (first numbers)
           primes []]
      (if (< current limit-sqrt)
        (let [sieve-seq (set (range current limit current))
              ^longs numbers (filter #(not (contains? sieve-seq %)) numbers)]
          (recur numbers (first numbers) (conj primes current)))
        (concat primes numbers)))))
```