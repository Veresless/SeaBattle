package SeaBattle
{
	service SeaBattle
	{
		event void oponentConectedEvent(1: int16 clientID);
		
		event void oponentShootEvent(1: int32 x, 2: int32 y, 3: int16 clientID);
		void setShootResponse(1: ShootRezult rezult, 2: int16 clientID);
		
		void setShoot(1: int32 x, 2: int32 y, 3: int16 clientID);
		event void shootResponseEvent(1: ShootRezult rezult, 2: int16 clientID);
		
		event void gameOver(1: bool rezult, 2: int16 clientID);

		void subscribe(1: int16 clientID);
		void unsubscribe(1: int16 clientID);
	}
	enum ShootRezult { Miss, Hit, Kill};
}
