#ifndef IPIECEINFO_H_
# define IPIECEINFO_H_

# include <string>

class IPieceInfo
{
  public:
  virtual bool		couldBeBreakable() const = 0;
  virtual unsigned int	pieceEaten() const = 0;
  virtual bool		canPlace() const = 0;
  virtual int	toScore() const = 0;
  virtual bool	canWin() const = 0;
  virtual ~IPieceInfo() {}
};

#endif /* !IPIECEINFO_H_ */
