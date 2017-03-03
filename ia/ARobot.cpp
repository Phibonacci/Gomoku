#include "ARobot.hh"
#include "Priority.hh"
#include <stdexcept>
#include <iostream>
namespace ia
{
	ARobot::ARobot(RGamePlay::GamePlay &game, IGamePlay::Piece color)
		: _game(game), _color(color)
	{
	}

	bool		ARobot::isBetter(RGamePlay::RPieceInformation *one, RGamePlay::RPieceInformation *two)
	{
		int index = _color - 1;
		if (one[index].valide != two[index].valide)
		{
			return one[index].valide;
		}

		//Compare self count
		if (one[index].volunerable != two[index].volunerable)
			return !one[index].volunerable;
		if (one[index].getHighestPattern().info.nbPiece >= 5)
		{
			std::cout << "debug1";
			return true;
		}

		if (one[index].comboCount > two[index].comboCount)
		{
			std::cout << "debug1";
			return true;
		}
		if (one[index].getHighestPattern().info.nbPiece > two[index].getHighestPattern().info.nbPiece)
		{
			std::cout << "debug1";
			return true;
		}
		if (one[index].getHighestPattern().info.nbPiece == two[index].getHighestPattern().info.nbPiece)
		{
			if (one[index].getHighestPattern().info.nbPiece >= 2)
			return one[index].getHighestPattern().info.splitted < two[index].getHighestPattern().info.splitted;
		}
		if (one[index].getHighestPattern().info.nbPiece < two[index].getHighestPattern().info.nbPiece)
			return false;
		if (one[index].captureCount > two[index].captureCount)
		{
			std::cout << "debug1";
			return true;
		}

		//Compare enemy count
		index = !index;
		if (one[index].comboCount > two[index].comboCount)
		{
			std::cout << "debug1";
			return true;
		}
		if (one[index].getHighestPattern().info.nbPiece > two[index].getHighestPattern().info.nbPiece)
		{
			return true;
		}
		if (one[index].getHighestPattern().info.nbPiece == two[index].getHighestPattern().info.nbPiece)
		{
			return one[index].getHighestPattern().info.splitted < two[index].getHighestPattern().info.splitted;
		}
		if (one[index].getHighestPattern().info.nbPiece < two[index].getHighestPattern().info.nbPiece)
		{
			//			std::cout << "debug13";
			return false;
		}
		if (one[index].captureCount > two[index].captureCount)
		{
			std::cout << "debug14";
			return true;
		}
		if (one[index].volunerable != two[index].volunerable)
			return !one[index].volunerable;
		return false;
	}

	bool		ARobot::isInteresting(RGamePlay::RPieceInformation *one)
	{
		int index = _color - 1;
		int level = 0;
		int combo = 0;

		if (!one[index].valide)
			return false;
		RGamePlay::RPattern pattern = one[index].getHighestPattern();
		if (pattern.info.nbPiece - pattern.info.isBlocked >= 4)
			return true;
		if (one[index].comboCount > 1)
			return true;
		if (one[index].captureCount >= 1)
			return true;

		//Compare enemy count
		index = !index;
		if (!one[index].valide)
			return false;
		if (one[index].getHighestPattern().info.nbPiece >= 3)
			return true;
		if (one[index].comboCount > 1)
			return true;
		if (one[index].captureCount >= 1)
			return true;
		return false;
	}

	Coord		ARobot::decide()
	{
		RGamePlay::RGameArbitre &arbitre(_game.getArbitre());
		unsigned int bestX = 0, bestY = 0;
		RGamePlay::RPieceInformation bestInfos[2];
		bool	anythingFound = false;
		int test = 0;
		RGamePlay::RPieceInformation tmpInfos[2];
		for (unsigned int y = 0; y < 19; ++y)
		{
			for (unsigned int x = 0; x < 19; ++x)
			{
				// if (!arbitre.pieceInformationUpdated(x, y))
				//	continue;
				if (arbitre.getPieceInformation(x, y, tmpInfos))
				{
					if (tmpInfos[_color - 1].valide)
					{
						Priority self(tmpInfos + _color - 1);
						Priority enemy(tmpInfos + !(_color - 1));

						if (self.getPriority() >= Priority::PRESSURE ||
							enemy.getPriority() >= Priority::PRESSURE)
						{
							++test;
						}
						if (isInteresting(tmpInfos))
						{
							;
							//std::cout << "AI think " << x << "," << y << " is interesting" << std::endl;
						}
						if (!anythingFound)
						{
							bestInfos[0] = tmpInfos[0];
							bestInfos[1] = tmpInfos[1];
							bestX = x;
							bestY = y;
							anythingFound = true;
						}
						else if (isBetter(tmpInfos, bestInfos))
						{
							std::cout << "isBetter " << x << " " << y << std::endl;
							bestInfos[0] = tmpInfos[0];
							bestInfos[1] = tmpInfos[1];
							bestX = x;
							bestY = y;
						}
					}
				}
			}
		}
		if (anythingFound)
		{
			//std::cout << "AI decided: " << bestX << " " << bestY << std::endl;
			std::cout << bestInfos[_color - 1].getHighestPattern().info.nbPiece << std::endl;
			std::cout << "Pressure count " << test << std::endl;
			return Coord(bestX, bestY);
		}
		else
			throw std::runtime_error("Nothing valide found");
	}
}
