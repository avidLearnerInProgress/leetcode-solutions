class Library:
    def __init__(self, id_, arr):
        [book_count, signup_time, per_day] = arr
        self.id = id_
        self.book_count = book_count
        self.signup_time = signup_time
        self.per_day = per_day
        self.books = []
        self.taken = False
    
    def print(self):
        print("id:",self.id,"Sign up:", self.signup_time, "Per day:", self.per_day, "Books:",self.book_count)
        # ,"books", self.books)
    
    def addBooks(self, bks):
        ranks = []
        for bk in bks:
            ranks.append((bk.rank, bk))
        
        ranks.sort(key=lambda x: x[0])
        self.books = [x for (y,x) in ranks]

        # print("----")
        # for bk in self.books:
        #     bk.print()
    
    def getScore(self, days):
        days_left = days-self.signup_time
        books_readable = days_left*self.per_day
        cnt = 0
        score = 0
        booksAdded = []
        # print(days_left, books_readable, self.per_day)
        for bk in self.books:
            if bk.id in bookIndicesAdded:
                continue
            score += bk.score
            cnt += 1
            booksAdded.append(bk)
            if cnt == books_readable:
                break
        self.score = score
        return score, booksAdded


class Book:
    def __init__(self, id_, rank, score):
        self.id = id_
        self.rank = rank
        self.score = score
    
    def print(self):
        print("id:",self.id,"rank:", self.rank,"score:", self.score)

def readFromFile(fp, outPath=None):
    with open(fp,'r') as f:
        data = f.read()
    data = data.split('\n')
    [B,L,D] = [int(x) for x in data[0].split(' ')]
    scores = [int(x) for x in data[1].split(' ')]

    k = list(zip(scores, list(range(B))))
    # print(k)
    # k.sort(key=lambda x: x[0], reverse=True)
    k.sort(key=lambda x: x[0], reverse=True)
    
    # print(k)
    booksByIndex = {}
    for r, (s,i) in enumerate(k):
        booksByIndex[i] = Book(i, r, s)

    libraries = []
    s = 0
    for i in range(L):
        lb = Library(i, [int(x) for x in data[2+(2*i)].split(' ')])
        lb.addBooks([booksByIndex[int(x)] for x in data[2+(2*i)+1].split(' ')])
        s += lb.signup_time
        libraries.append(lb)

    r = solution(B,L,D, scores, libraries,booksByIndex)

    if r is not None:
        with open(outPath, 'w') as f:
            f.write(r)

def solution(B, L, D, scores_original, libraries, booksByIndex):
    global bookIndicesAdded, total_max_score
    bookIndicesAdded = set()
    # scores = []
    # for lb in libraries:
    #     score, _ = lb.getScore(D)
    #     scores.append((score, lb))
    
    # scores.sort(key=lambda x: x[0])
    s = ""
    days_left = D
    lib_cnt = 0
    maxScore = 0
    for _ in range(len(libraries)):
        scores = []
        for lb in libraries:
            if lb.taken:
                continue
            score, _ = lb.getScore(D)
            # print(score)
            scores.append((score, lb, lb.per_day, lb.signup_time))
        
        # scores.sort(key=lambda x: x[0],reverse=True)
        scores = sorted(scores, key=lambda x: (-x[3],x[0],x[2]), reverse=True)
        _, lb, _, _ = scores[0]
        lb.taken = True
        if days_left < lb.signup_time:
            break
        score, booksAdded = lb.getScore(days_left)
        days_left -= lb.signup_time
        if len(booksAdded) == 0:
            continue
        lib_cnt += 1
        s += str(lb.id) + " " + str(len(booksAdded)) + "\n"
        for bk in booksAdded:
            bookIndicesAdded.add(bk.id)
            s += str(bk.id) + " "
            maxScore += bk.score
        s += "\n"
    
    s = str(lib_cnt) + "\n" + s[:-1]

    print(maxScore, (sum(scores_original)-maxScore)/1000000)
    total_max_score += maxScore
    return(s)
    

names = ["e_so_many_books", "f_libraries_of_the_world"]
# names = ["test_1", "test_2"]

#names = names[:-1]
# names = names[-2:-1]

# from time import time
# st = -time()
total_max_score = 0
for name in names:
    print(name, end=" => ")
    readFromFile("./" + name + ".txt", "./" + name + ".out")
    # break
print(total_max_score-14626515)