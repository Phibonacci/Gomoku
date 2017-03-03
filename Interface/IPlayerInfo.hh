#ifndef IPLAYERINFO_H_
# define IPLAYERINFO_H_

class IPlayerInfo
{
public:
  virtual bool			hasWon(IGamePlay::Rule) const = 0;
  virtual IGamePlay::Piece	getColor() const = 0;
  virtual unsigned int		pieceEaten() const = 0;
  virtual ~IPlayerInfo() {}
};

#endif /* !IPLAYERINFO_H_ */
