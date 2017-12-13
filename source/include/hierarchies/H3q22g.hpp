#pragma once

#include <map>

namespace himalaya{
   
   class H3q22g{
   public:
      /**
       * 	Constructor
       * 	@param flagMap the flagMap for the truncation of expansion variables
       * 	@param Al4p a double alpha_s/4/Pi
       * 	@param beta a double which is the mixing angle beta
       * 	@param Dmglst1 a double Mgl - Mst1
       * 	@param Dmst12 a double Mst1^2 - Mst2^2
       * 	@param Dmsqst1 a double Msq^2 - Mst1^2
       * 	@param lmMt a double log((<renormalization scale> / Mt)^2)
       * 	@param lmMst1 a double log((<renormalization scale> / Mst1)^2)
       * 	@param Mt a double top/bottom quark mass
       * 	@param Mst1 a double stop 1 mass
       * 	@param Mst2 a double stop 2 mass
       * 	@param Msq a double average squark mass w/o the stop quarks
       * 	@param MuSUSY a double mu parameter
       * 	@param s2t a double 2 times the sine of the stop/sbottom quark mixing angle
       * 	@param mdrFlag an int 0 for DR and 1 for MDR scheme
       * 	@param oneLoopFlag an int flag to consider the one-loop expansion terms
       * 	@param twoLoopFlag an int flag to consider the two-loop expansion terms
       * 	@param threeLoopFlag an int flag to consider the three-loop expansion terms
       */
      H3q22g(const std::map<unsigned int, unsigned int>& flagMap, double Al4p, double beta,
		 double Dmglst1, double Dmst12, double Dmsqst1, double lmMt, double lmMst1,
		 double Mt, double Mst1, double Mst2, double Msq, double MuSUSY,
		 double s2t,
		 int mdrFlag, int oneLoopFlag, int twoLoopFlag, int threeLoopFlag);
      /**
       * 	@return The diagonal (1, 1) matrix element of the Higgs mass matrix as a double for the hierarchy 'H3q22g'
       */
      double getS1();
      /**
       * 	@return The diagonal (2, 2) matrix element of the Higgs mass matrix as a double for the hierarchy 'H3q22g'
       */
      double getS2();
      /**
       * 	@return The off-diagonal (1, 2) = (2, 1) matrix element of the Higgs mass matrix as a double for the hierarchy 'H3q22g'
       */
      double getS12();
      /**
       * 	@return returns the susy log^0 term of Mh^2 @ O(at*as^2) without any log(mu^2) terms normalized to DO (H3m*12/Mt^4/Sbeta^2)
       */
      double calc_coef_at_as2_no_sm_logs_log0();
      /**
       * 	@return returns the susy log^1 term of Mh^2 @ O(at*as^2) without any log(mu^2) terms normalized to DO (H3m*12/Mt^4/Sbeta^2)
       */
      double calc_coef_at_as2_no_sm_logs_log1();
      /**
       * 	@return returns the susy log^2 term of Mh^2 @ O(at*as^2) without any log(mu^2) terms normalized to DO (H3m*12/Mt^4/Sbeta^2)
       */
      double calc_coef_at_as2_no_sm_logs_log2();
      /**
       * 	@return returns the susy log^3 term of Mh^2 @ O(at*as^2) without any log(mu^2) terms normalized to DO (H3m*12/Mt^4/Sbeta^2)
       */
      double calc_coef_at_as2_no_sm_logs_log3();
   private:
      double Dmglst1{}, Dmst12{}, Dmsqst1{}, lmMst1{}, Mt{}, Mst1{}, Mst2{}, Msq{}, MuSUSY{}, s2t{}, Tbeta{}, Sbeta{}; /**< common variables */
      int shiftst1{}, shiftst2{}, shiftst3{}, xDmst12{}, xDmglst1{}, xDmsqst1{}; /**< MDR and truncation flags */
      double s1{}, s2{}, s12{};	/**< The Higgs mass matrix elements s1 = (1, 1), s2 = (2, 2), s12 = (1, 2) = (2, 1) */
   };
}	// himalaya
