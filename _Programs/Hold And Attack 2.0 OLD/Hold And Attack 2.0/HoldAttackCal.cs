using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hold_And_Attack_2._0
{
    public enum Operation { HOLD, DEFENSE, ATTACK, ATTACK_FAIL, ERROR_CODE, INPUT_FAIL };
    public enum Personality { EASY, DEFAULT, NORMAL };

    public class Player
    {
        // data members
        public const int HEALTH_DEFAULT = 10;
        
        public List<Operation> storage;
        int numHold = 0;
        int numDefense = 0;
        string plName = "Player";
        Random random = new Random();			// should assure that the default pesudo in Constructor in Random.h is false! 
        int health = HEALTH_DEFAULT;

        public Player()
        {
            Clear();
            plName = "Player";
            random.Next(1, 100);// this is dummy， then will be effective
            storage = new List<Operation>();
            RecoverHealth();
        }

        public Operation Act(Operation op)
        //	Pre:	op should only be HOLD, DEFENSE, or ATTACK.
        //	Post:	Act according to the direction given, like if it is HOLD,
        //			then storage is changed according to this deriction. Simutanously,
        //			give out a result that "HOLD".
        {
            switch (op)
            {
                case Operation.HOLD:
                    return ActIfHold(); 
                case Operation.DEFENSE:
                    return ActIfDef(); 
                case Operation.ATTACK:
                    return ActIfAttk();
                default:
                    return Operation.ERROR_CODE; 
            }
        }

        protected Operation ActIfHold()
        {
            storage.Insert(storage.Count, Operation.HOLD);
            numHold++;
            numDefense = 0;
            return Operation.HOLD;
        }

        protected Operation ActIfDef()
        {
            storage.Insert(storage.Count, Operation.DEFENSE);
            numDefense++;
            return Operation.DEFENSE;
        }

        protected Operation ActIfAttk()
        {
            if (numHold == 0)
                return Operation.ATTACK_FAIL;
            else if (numHold < 0)
                return Operation.ERROR_CODE;
            else
            {
                storage.Insert(storage.Count, Operation.ATTACK);
                numHold--;
                numDefense = 0;
                return Operation.ATTACK;
            }
        }

        public Operation AI_Decide(Player rival, Personality pnty)
        //	Post:	return the option AI will choose. There'll be no possibility
        //			of ATTACK_FAIL, but will be able to be EEROR_CODE which can
        //			be induced by resNum being out of range(1--100）or numHold < 0.
        {
            /**	How to decide?
            *	using resNum(1 to 100), and Random() Function,
            *	and a threshold, then we can acquire a decision.
            */
            int resNum;			    // result number according to random()
            int numRivalHold = rival.GetNumHold();
            int thresholdL = 60;	// in default, <= it will "HOLD", else "ATTACK"
            int thresholdH = 100;	// in default, <= it && > thresholdL will ""ATTACK", else "DEFENSE"

            switch (pnty)	// !!currently hard only
            {
                    case Personality.EASY:
                    if (numRivalHold == 0)	// no holds
                    {
                        // Won't defend
                        thresholdH = 100;
                        thresholdL = 60;
                        if (numHold == 0)			// no holds, no chance to attck
                            return Operation.HOLD;
                        else if (numHold == 1)
                            thresholdL = 50;
                        else if (numHold == 2)
                            thresholdL = 30;
                        else if (numHold >= 3)	// There are too many HOLDs, then tend to attack
                            thresholdL = 10;
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 1)
                    {
                        // Will do all three actions
                        if (numHold == 0)			// no holds, defend or hold
                            thresholdH = thresholdL = 60;
                        else if (numHold == 1)
                        {
                            thresholdL = 40;
                            thresholdH = 80;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 30;
                            thresholdH = 90;
                        }
                        else if (numHold >= 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 20;
                            thresholdH = 100;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 2)
                    {
                        // Will do all three actions, but not tend to HOLD
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 30;
                        }
                        else if (numHold == 1)
                        {
                            thresholdL = 40;
                            thresholdH = 70;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 20;
                            thresholdH = 70;
                        }
                        else if (numHold >= 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 10;
                            thresholdH = 70;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold > 2)
                    {
                        // Will do all three actions, but go into defense state
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 20;
                        }
                        else if (numHold == 1)
                        {
                            thresholdL = 30;
                            thresholdH = 60;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 20;
                            thresholdH = 70;
                        }
                        else if (numHold > 3)	// same that have many HOLDs, tend to defense
                        {
                            thresholdL = 10;
                            thresholdH = 80;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }
                    break;

                case Personality.DEFAULT:
                    if (numRivalHold == 0)	// no holds
                    {
                        // Won't defend
                        thresholdH = 100;
                        thresholdL = 60;
                        if (numHold == 0)			// no holds, no chance to attck
                            return Operation.HOLD;
                        else if (numHold > 0 && numHold <= 3)
                            thresholdL -= numHold * 5;
                        else if (numHold > 3)	// There are too many HOLDs, then tend to attack
                            thresholdL = 10;
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 1)
                    {
                        // Will do all three actions
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 50;
                        }
                        else if (numHold > 0 && numHold <= 3)
                        {
                            thresholdL = 20;
                            thresholdH = 60;
                        }
                        else if (numHold > 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 5;
                            thresholdH = 70;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 2)
                    {
                        // Will do all three actions, but not tend to HOLD
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 30;
                        }
                        else if (numHold > 0 && numHold <= 3) //tend to defense
                        {
                            thresholdL = 15;
                            thresholdH = 45;
                        }
                        else if (numHold > 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 10;
                            thresholdH = 75;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold > 2)
                    {
                        // Will do all three actions, but go into defense state
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 5;
                        }
                        else if (numHold > 0 && numHold <= 3)	// more tend to defense 
                        {
                            thresholdL = 15;
                            thresholdH = 45;
                        }
                        else if (numHold > 3)	// same that have many HOLDs, tend to defense
                        {
                            thresholdL = 10;
                            thresholdH = 40;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }
                    break;

                case Personality.NORMAL:
                    if (numRivalHold == 0)	// no holds
                    {
                        // Won't defend
                        thresholdH = 100;
                        if (numHold == 0)			// no holds, no chance to attck
                            return Operation.HOLD;
                        else if (numHold == 1)
                            thresholdL = 50;
                        else if (numHold == 2)
                            thresholdL = 30;
                        else if (numHold >= 3)	// There are too many HOLDs, then tend to attack
                            thresholdL = 10;
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 1)
                    {
                        // Will do all three actions
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 50;
                        }
                        else if (numHold == 1)
                        {
                            thresholdL = 33;
                            thresholdH = 66;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 20;
                            thresholdH = 80;
                        }
                        else if (numHold >= 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 10;
                            thresholdH = 90;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold == 2)
                    {
                        // Will do all three actions, but not tend to HOLD
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 30;
                        }
                        else if (numHold == 1) //tend to defense
                        {
                            thresholdL = 20;
                            thresholdH = 40;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 15;
                            thresholdH = 57;
                        }
                        else if (numHold >= 3)	// more holds than rival, tend to attack
                        {
                            thresholdL = 10;
                            thresholdH = 70;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }

                    else if (numRivalHold > 2)
                    {
                        // Will do all three actions, but go into defense state
                        if (numHold == 0)			// no holds, defend or hold
                        {
                            thresholdH = thresholdL = 10;
                        }
                        else if (numHold == 1)	// more tend to defense 
                        {
                            thresholdL = 10;
                            thresholdH = 20;
                        }
                        else if (numHold == 2)
                        {
                            thresholdL = 10;
                            thresholdH = 40;
                        }
                        else if (numHold >= 3)	// same that have many HOLDs, tend to defense
                        {
                            thresholdL = 10;
                            thresholdH = 60;
                        }
                        else					// numHold < 0
                            return Operation.ERROR_CODE;
                    }
                    break;
            }

            resNum = random.Next(1, 100);						// effective	

            // check if has 5 DEFENSEs in a row
            if (numDefense >= 5)									// can't continue to defend
            {
                thresholdL += (100 - thresholdH) / 2;
                thresholdH = 100;
            }
            else if (numDefense < 0)									// ERROR_CODE happens
            {
                return Operation.ERROR_CODE;
            }

            if (resNum > 0 && resNum <= thresholdL)					// hold
                return Operation.HOLD;
            else if (resNum > thresholdL && resNum <= thresholdH)	// attack
                return Operation.ATTACK;
            else if (resNum > thresholdH && resNum <= 100)			// defend
                return Operation.DEFENSE;
            else													// error
                return Operation.ERROR_CODE;
        }

        public int GetNumHold()
        {
            return numHold;
        }

        public int GetNumDefense()
        {
            return numDefense;
        }

        public void Clear()
        {
            if (storage != null) 
                storage.Clear();
            numHold = 0;
            numDefense = 0;
            RecoverHealth();
        }


        public void SetPlName(string str)
        {
            plName = str;
        }

        public string GetPlName()
        {
            return plName;
        }

        public bool ReduceHealth(int value)
        //  Pre:    一般value需要=1
        //  Post:   傷血,返回是否血條打光(輸了),輸了是true
        {
            health -= value;
            return health <= 0;
        }

        public int GetHealth()
        {
            return health;
        }

        public void RecoverHealth()
        {
            health = HEALTH_DEFAULT;
        }
    }
}
