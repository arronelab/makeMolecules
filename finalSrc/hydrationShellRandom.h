#ifndef HYD_SH_M
#define HYD_SH_M

#include "ktlMoleculeRandom.h"
#include <algorithm>  
#include <functional> 


class hydrationShellMinimal{
public:
  hydrationShellMinimal(){};
  hydrationShellMinimal(ktlMolecule &molIn,double RinInp,double RoutInp,double &RhyIn,int ntrivsIn,double helixRatioIn,int solventsPerLinkIn,double &mutualDistCutOffIn,double &rmin,double &rmax,double &lmin);
  void resetMol(ktlMolecule &molIn);
  void getPointAndMidlengthHelix(int i,int &hIndex);
  void getPointAndMidlengthMulti(int i,int &hIndex);
  void getPointAndMidlengthStraight(int &sec,int &part,int &hIndex,std::string soe);
  void tubeParamList();
  void updateTubeParamList(int &index,int &startHIndex);
  point getDirec(int i);
  point getHydTan(int i);
  point getHydNorm(int i);
  point getHydBinorm(int i);
  double hydTubeLength(int i);
  point hydTubeCentre(int i);
  point getTangent(int index,int subindex);
  point getNormal(int index,int subindex);
  point getBinormal(int index,int subindex);
  point getCentrePoint(int index,int subIndex);
  int getNScat();
  void resetMolecule();
  int getMolSize();
  int getNoSections();
  int getNoKvals();
  double getMaxDist();
  void makeInitialSegData(point &cp,point &T,point &N1,double &tm,int index,int &nseg);
  void updateSegData(point &cp,point &T,point &N1,double &tm,int index,int &nseg);
  void constructInitialState();
  std::vector<std::vector<point> > getHydrationLayer(int i);
  std::vector<std::vector<int> > getTruthTable(int i);
  void updateTruthTableTest(int &ind1,int &ind2,double &R);
  std::pair<std::vector<std::vector<double> >,std::pair<std::string,std::string>  > getMinTvalsFiniteNew(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2);
  std::pair<std::vector<std::vector<double> >,std::pair<std::string,std::string>  > getMinTvalsFiniteNewTest(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2);
   void overlapPodstruct(int i,int j,int inch,int jnch);
   void overlapPodstructJoined(int i,int j);
   std::pair<std::vector<point>,std::string> getEllipseOf1(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,std::vector<double> &sol);
   std::pair<std::vector<point>,std::string> getEllipseOf2(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,std::vector<double> &sol);
   std::pair<std::vector<point>,std::string> getEllipseOf1Test(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,std::vector<double> &sol);
   std::pair<std::vector<point>,std::string> getEllipseOf2Test(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,std::vector<double> &sol);
   bool checkIsIn1(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &sol1,double &sol2,int inch,int jnch,double &R1,double &R2);
   bool checkIsIn2(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &sol1,double &sol2,int inch,int jnch,double &R1,double &R2);
   bool checkIsIn1(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,point &r2cp,point &r12,point &J,point &ellipsePoint,double &t2param,int i,int j);
   bool checkIsIn2(point &cp1,point &cp2,point &T1,point &T2,double &tm1,double &tm2,double &R1,double &R2,point &r1cp,point &r2e,point &J,point &ellipsePoint,double &t1param,int i,int j);
   void allOverlap();
   void allOverlap(int &ChangeIndex);
   void allOverlapOne(int index);
   void printOnePod(int index);
   void calculateHelix(int index);
   void getAllHelices();
   void printHelices(int index);
   void printHelicesFlat(int index);
   void updateHelices(int &changeIndex);
   void updateHelicesSimple(int &changeIndex);
   std::vector<std::pair<int,double> > countDistances(int index);
   void printSelfDistances(int index);
   double helixDistFunc(int &d, int &index,int &npts);
   void selfScatteringSingleFast(int &nscat,double &kmin,double &kmax,int index);
   void selfScatteringSingleFastRT(int &nscat,double &kmin,double &kmax,int index);
   void printOneSelfScatter(int index);
   void printTotalOneMutualScatter(int index1,int index2);
   double returnTotalOneMutualScatter(int index1,int index2);
   void selfScatteringAll(int &nscat,double &kmin,double &kmax);
   void sectionAndSectionFull(int &nscat,double &kmin,double &kmax,int index1,int index2);
   void sectionAndSectionUpdateLow(int &nscat,double &kmin,double &kmax,int index1,int index2);
   void mutualScatteringAll(int &nscat,double &kmin,double &kmax,int index);
   void getAllScatter(int &nscat,double &kmin,double &kmax);
   void selfScatteringAllRT(int &nscat,double &kmin,double &kmax);
   void sectionAndSectionFullRT(int &nscat,double &kmin,double &kmax,int index1,int index2);
   void sectionAndSectionUpdateLowRT(int &nscat,double &kmin,double &kmax,int index1,int index2);
   void mutualScatteringAllRT(int &nscat,double &kmin,double &kmax,int index);
   void getAllScatterRT(int &nscat,double &kmin,double &kmax);
   void getFlatSolList();
   void solventMoleculeDistances(std::vector<double> &molSolDistances,std::vector<double> &solSolDistances);
   std::vector<std::vector<point> > returnFlatSolList();
   std::vector<double> flattenVector(std::vector<std::vector<std::vector<double> > > &vec);
   std::vector<int> binDistancesMolecule();
   std::vector<int> binDistancesSolvent();
   std::vector<int> binDistancesSolventMolecule();
   bool isCutOffViolated();
   double getCuttOffDistMutual();
   void setNScat(double &kmin,double &kmax);
   void preCalculatePhases(double &kmin,double &kmax);
   void preCalculatePhasesRT(double &kmin,double &kmax);
   void getInitialScatter(int &nk,double &kmin,double &kmax);
   void getInitialScatterRT(int &nk,double &kmin,double &kmax);
   void addScatteringLists(std::vector<std::pair<double,double> > &l1,std::vector<std::pair<double,double> > &l2);
   void getScatteringBinnedRT(double &kmin,double &kmax);
   void getScatteringBinnedRTUpdate();
   void getScatteringBinnedRTUpdate(int &changeIndex);
   void getUpdate(int &changeIndex);
   std::vector<std::pair<int,double> > binDistances();
   std::vector<std::vector<int> > findPointsInbetweenLayer(double c,double kap,double tau,double phi,double psi,double theta,std::vector<double> arcLengthTable,std::vector<std::pair<double,double> > distTable);
   void generateTableOneDistance(int ntheta,int nphi,int npsi,double c,double kap,double tau,double al,int npts,std::vector<std::pair<double,double> > distTable,int distBin);
   void writeOneDistanceFileToFile(std::vector<std::vector<std::vector<std::vector<std::vector<int> > > > >  &thetaList,int &distBin);
   void readOneDistanceFromFile(int thetaSize,int phiSize,int psiSize,int &distBin,int &maxNoPts,int &noBinsInFile);
   void selectDistances(double &dist,int &theAng,int &phiAng,int &psiAng,int &currDindex,int noMol,std::vector<int> &molDistances,std::vector<int> &solDistances,int &molIndex);
   std::vector<int> selectAngles(double the,double phi,double psi);
   void setUpDistanceAngleLists(int ntheta,int nphi,int npsi,int noBinsToRead);
   void calculateScatteringBinned(int noBinsToRead);
   void getCentreDistances();
   void generateAllTables(int ntheta,int nphi,int npsi,double kap,double tau,double al,int nptsHelix,int noBins);
   void readInHelixDistances(int ntheta,int nphi,int npsi,int noBinsToRead,int maxNoPts);
   void printOneMutualScatter(int index1,int index2);
   std::vector<std::pair<double,double> > getTotalSelfScatter();
   void addOneScatterSelf(int &nscat,int &index);
   void addOneScatterMutual(int &nscat,int &index1,int &index2);
   void printTotalScatter();
   void printIndicies(int index);
   void printIndiciesPrev(int index);
   void writeHydrationShellToFile(const char* filename);
   std::vector<std::vector<std::vector<int> > > getIndicies(int index);
   std::vector<std::vector<int> > getTTS(int index);
   void printShellFrame(int index);
   void printMinDists(int index);
   int getNoScatPoints();
   void writeTotalScatterToFile(const char* filename);
   void updateHydration(int &index);
   void reverseOverlapsNew(int &podIndex,int &changeIndex,int &changeIndexUp,std::vector<int>  &sublistAbove,std::vector<int> &sublistBelow);
   void updateHydrationNew(int &changeIndex);
   void updateState(int &index);
   void reverseOverlaps(int &podIndex,int &changeIndex);
   void updateFlatSolList(int &changeIndex);
   void updateScattering(int &nscat,double &kmin,double &kmax,int &changeIndex);
   std::vector<int> updateBinDistancesMolecule(int &changeIndex);
   std::vector<int> updateBinDistancesSolvent(int &changeIndex);
   std::vector<int> updateBinDistancesSolventMolecule(int &changeIndex);
   std::vector<std::pair<double,double> > updateBinDistancesMoleculeTest(int &nscat,double &kmin,double &kmax,int &changeIndex);
   std::vector<std::pair<double,double> > updateBinDistancesSolventTest(int &nscat,double &kmin,double &kmax,int &changeIndex);
   std::vector<std::pair<double,double> > updateBinDistancesSolventMoleculeTest(int &nscat,double &kmin,double &kmax,int &changeIndex);
   void updateScatteringBinnedTest(double &kmin,double &kmax,int &changeIndex,int &changeIndexLow,int &changeIndexHigh);
   void changeConfigurationBinned(int &changeIndex,double &kmin,double &kmax);
   void changeConfigurationBinnedFull(int &changeIndex);
   void changeConfigurationBinnedFullFast(int &changeIndex);
   void changeConfigurationLocalBinnedFull(std::vector<int> &changeIndicies,double &variationSize);
  void changeMoleculeSingle(int &index);
  void changeMoleculeSet(std::vector<int> &indicies);
  void changeMoleculeSingleMulti(int &index,int secIn);
  void changeMoleculeSetMulti(std::vector<int>  &indicies,int secIn);
  void changeMoleculeMultiRotate(double &angle,point &k,int secIn,point &transVec);
  void replicateMolecule(int &noReplications);
  void changeMoleculeLocal(int &index,double variationSize);
  void changeMoleculeLocalSet(std::vector<int> &indicies,double variationSize);
  void changeMoleculeSingle(int &index,std::vector<std::vector<point> > &cdsIn,std::vector<std::pair<std::string,int> > &nameSizeSubList);
  int getSubsecSize(int sec);
  double maxNeighbourDistSec(int &sec);
  std::vector<double> checkOverlapWithRad(double &wRad);
  void getHydrophobicResidues();
  void getCoiledCoilResidues();
  double getGlobalRadiusOfCurvature();
  double getGlobalRadiusOfCurvatureBetweenSec();
  double coiledCoilPotential();
  double coiledCoilPotentialBetween();
  double getFitQualSbonds(std::vector<std::tuple<std::pair<int,int>,std::pair<int,int>,double> > &contactPairList,double weightCoeff);
  double compareDistances(std::vector<std::vector<point> > &coords2);
  std::string getType(int &chainIndex,int &index);
  std::vector<std::vector<point> > getCoordinates();
   std::vector<std::pair<double,double> > getSolScatter();
   std::vector<std::pair<double,double> > getMolScatter();
   std::vector<std::pair<double,double> > getSolMolScatter();
   std::vector<std::vector<std::pair<double,double> > > getSelfSolScatter();
   std::vector<std::vector<std::pair<double,double> > > getSelfMolScatter();
   std::vector<std::vector<std::pair<double,double> > > getSelfSolMolScatter();
   std::vector<std::vector<std::vector<std::pair<double,double> > > > getMutualSolScatter();
   std::vector<std::vector<std::vector<std::pair<double,double> > > > getMutualMolScatter();
   std::vector<std::vector<std::vector<std::pair<double,double> > > > getMutualSolMolScatter();
   void writeMoleculeToFile(const char* filename);
   int getNoBins(double kmin,double kmax);
   void writeHelixPointsToFile(const char* filename);
   void writeHydrationParametersaToFile(const char* filename);
   void getBackboneStats();
   std::vector<std::pair<double,double> > getKapTauVals();
 private:
  void updateTruthTable(int &ind1,int &ind2,double &R);
  ktlMolecule mol;
  polyHelix ph;
  std::vector<point> direcList;
  std::vector<point> frameTan;
  std::vector<point> frameNorm;
  std::vector<point> frameBinorm;
  std::vector<point> midPointList;
  std::vector<std::string> nameLst;
  std::vector<int> lengthSec;
  std::vector<double> halfLengthList,cstepList;
  int molsize;
  double Pi,Rin,Rout,Rhy;
  std::vector<int> distBinsMol;
  std::vector<int> distBinsSol;
  std::vector<int> distBinsSolMol;
  std::vector<double> edgesolset1,edgesolset2,edgesolset3,edgesolset4,middlesol;
  std::pair<std::string,std::string> typeMessage;
  std::vector<std::vector<std::vector<point> > > allSegments;
  std::vector<std::vector<std::vector<int> > > allTruthTables;
  std::vector<std::vector<std::vector<std::vector<int> > > > indexList;
  std::vector<std::vector<std::vector<std::vector<int> > > > indexListPrev;
  int solventsPerLink;
  double helixRatio;
  int ntrivs;
  std::vector<std::vector<point> > helixpts;
  std::vector<std::vector<point> > helPtsFlat;
  std::vector<std::vector<point> > solPtsFlat;
  std::vector<std::vector<std::pair<double,double> > > selfScatteringListSol;
  std::vector<std::vector<std::pair<double,double> > > selfScatteringListMol;
  std::vector<std::vector<std::pair<double,double> > > selfScatteringListSolMol;
  std::vector<std::vector<std::vector<std::pair<double,double> > > > mutualScatteringListSol;
  std::vector<std::vector<std::vector<std::pair<double,double> > > > mutualScatteringListMol;
  std::vector<std::vector<std::vector<std::pair<double,double> > > > mutualScatteringListSolMol;
  std::vector<std::pair<double,double> > totalScatterSol;
  std::vector<std::pair<double,double> > totalScatterMol;
  std::vector<std::pair<double,double> > totalScatterSolMol;
  std::vector<std::pair<double,double> > emptyScatterSol;
  std::vector<std::pair<double,double> > emptyScatterMol;
  std::vector<std::pair<double,double> > emptyScatterSolMol;
  std::vector<std::pair<double,double> > mutualScatterSol;
  std::vector<std::pair<double,double> > mutualScatterMol;
  std::vector<std::pair<double,double> > mutualScatterSolMol;
  std::vector<bool> hydrationChangeList;
  std::vector<std::vector<std::vector<double> > > molmolDistSum;
  std::vector<std::vector<std::vector<double> > > solsolDistSum;
  std::vector<std::vector<std::vector<double> > > molsolDistSum;
  std::vector<std::vector<std::vector<double> > > solmolDistSum;
  std::vector<std::vector<double> > distanceSets;
  std::vector<std::pair<double,double> > distanceList;
  std::vector<std::pair<std::vector<std::pair<double,int> >,int> > minimumDistances;
  std::vector<std::vector<double> > phaseList;
  int solIntbound,molIntbound,solmolIntbound,nscat,nSize;
  double maxDistChange,kminVal,kmaxVal,maxDistVal,maxdist,maxScatDist,mutualDistCutOff;
  bool isTooClose;
};

#endif
