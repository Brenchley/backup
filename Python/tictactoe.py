import random
import sys
import copy


class Game:
	"Tic-Tac-Toe class. This class holds the user interaction, and game logic"
	def __init__(self):
		self.board=[''] * 9
		self.player_name=''
		self.player_marker=''
		self.bot_name='TBot'
		self.bot_marker=''
		self.winning_combos=(
			[6,7,8],[3,4,5],[0,1,2],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6],
			)
		self.corners = [0,2,6,8]
		self.sides =[1,3,5,7]
		self.middle = 4
		self.form ='''
			\t|%s|%s|%s|
			\t------------
			\t|%s|%s|%s|
			\t------------
			\t|%s|%s|%s|
			'''

		def print_board(self,board=None):
			"Display board on screen"
			if board is None:
				print self.form % tuple(self.board[6:9] + self.board[3:6] + self.board[0:3])
			else:
				#when the game starts, display numbers on all the grids
				print self.form % tuple(board[6:9] + board[3:6] + board[0:3])

		def get_marker(self):
			marker = raw_input("Would you like to be X or O ?: ").upper()
			while marker not in ["X", "O"]:
				marker = raw_input("Would you like to be X or O ?: ").upper()
			if marker == "X":
				return ('X', 'O')
			else:
				return ('O', 'X')

		def help(self):
			print '''
			\n\t The game board has 9 squares (3x3).
			\n\t Two players take turns in marking the spots/grids on the board.
			\n\t The first player to have 3 pieces in a horizontal, vertical or diagonal row wins the game
			\n\t To place your mark in the desired square, simply type the number corresponding with the square on the grids

			\n\t Press Crtl + C to quit 
			'''

		def quit_game(self):
			"exit game"
			self.print_board
			print  "\n\t Thanks for playing :-) \n\t Come play again soon!\n"
			sys.exit()
		def is_winner(self, board, marker):
			"check if this marker will win the game"
			#order of checks:
			#	1. across the horizontal top
			#	2. across the horizontal middle
			#	3. across the horizontal bottom
			#	4. across the vertical left
			# 	5. across the vertical middle
			#	6. across the vertical right
			#	7. across first diagonal
			#	8. across second diagonal
			for combo in self.winning_combos:
				if (board[combo[0]] == board[combo[1]] == board[combo[2]] == marker):
					return True

		def get_bot_move(self):
			'''
			find the best space on the board for the bot. Objective
			is to find a winning move, a blocking move or an equalizer move.
			Bot must always win
			'''
			#check if bot can win in the next move
			for i in range(0,len(self.board)):
				board_copy = copy.deepcopy(self.board)
				if self.is_space_free(board_copy, i):
					self.make_move(board_copy, i, self.bot_marker)
					if self.is_winner(board_copy, self.bot_marker):
						return i

			#check if player could win on thier next move
			for i in range(0,len(self.board)):
				board_copy = copy.deepcopy(self.board)
				if self.is_space_free(board_copy, i):
					self.make_move(board_copy, i, self.player_marker)
					if self.is_winner(board_copy, self.player_marker):
						return i
			# check for space in the corner, and take it
			move = self.choose_random_move(self.corners)
			if move != None:
				return move
			# if the middle is free, take it
			if self.is_space_free(self.board,self.middle):
				return self.middle

			#else, take one free space on the sides 
			return self.choose_random_move(self.sides)

		def is_space_free(self,board,index):
			"check for free space of the board"#prin

