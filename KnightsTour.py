





class ChessBoard():


    def __init__(self,n) -> None:
        self.n = n\

        self.chessboard = {(x,y): [] for x in range(1, (n + 1)) for y in range(1, (n + 1))}

        self.R = [(-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1,-2)]

        for i in self.chessboard.keys():
            for offset in self.R:
                new_dot = (i[0] + offset[0], i[1] + offset[1])
                if new_dot in self.chessboard and new_dot not in self.chessboard[i] :
                    self.chessboard[i].append(new_dot)



        self.length = len(self.chessboard)


        print(self.chessboard)

        print('=====================================================================================')



    def horse_step(self, x, y ):
        path = []
        tryed = None

        
        current = (x,y)
        path.append((x,y))

        while self.length != len(path):
            move_found = False
            print(path)
            if tryed is None:
                start = 0
            else:
                try:
                    start = self.chessboard[current].index(tryed) + 1
                    
                except ValueError:
                    print('ERROR: ', current, tryed, sep=' \n')
                    
                    quit()

           
            for dot in range(start, len(self.chessboard[current])):
                print(current ,'///')
                if (self.chessboard[current][dot] not in path) and (self.chessboard[current][dot] != tryed):
                    print(path)
                    print(current, "->", self.chessboard[current][dot])
                    tryed = None
                    path.append(self.chessboard[current][dot])
                    print(path)
                    current = self.chessboard[current][dot]
                    move_found = True
                    break

            if not move_found:

                    tryed = current
                    print(tryed)
                    path.pop()
                    current = path[-1]
                    

        # print(len(path))
        print(path)

board =  ChessBoard(5)
board.horse_step(1,1)
# print(board.chessboard[(3,5)])