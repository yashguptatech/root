// @(#)root/geom:$Name:  $:$Id: TGeoTrd1.h,v 1.2 2002/07/10 19:24:16 brun Exp $
// Author: Andrei Gheata   24/10/01

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TGeoTrd1
#define ROOT_TGeoTrd1

#ifndef ROOT_TGeoBBox
#include "TGeoBBox.h"
#endif


 /*************************************************************************
 * TGeoTrd1 - a trapezoid with only x length varying with z. It has 4
 *   parameters, the half length in x at the low z surface, that at the
 *   high z surface, the half length in y, and in z
 *
 *************************************************************************/

class TGeoTrd1 : public TGeoBBox
{
protected:
   // data members
   Double_t              fDx1; // half length in X at lower Z surface (-dz)
   Double_t              fDx2; // half length in X at higher Z surface (+dz)
   Double_t              fDy;  // half length in Y
   Double_t              fDz;  // half length in Z
public:
   // constructors
   TGeoTrd1();
   TGeoTrd1(Double_t dx1, Double_t dx2, Double_t dy, Double_t dz);
   TGeoTrd1(Double_t *params);
   // destructor
   virtual ~TGeoTrd1();
   // methods
   virtual Int_t         GetByteCount() const {return 52;}
   Double_t              GetDx1() const {return fDx1;}
   Double_t              GetDx2() const {return fDx2;}
   Double_t              GetDy() const  {return fDy;}
   Double_t              GetDz() const  {return fDz;}

   virtual void          ComputeBBox();
   virtual Bool_t        Contains(Double_t *point) const;
   virtual Double_t      DistToOut(Double_t *point, Double_t *dir, Int_t iact=1, 
                                   Double_t step=0, Double_t *safe=0) const;
   virtual Double_t      DistToIn(Double_t *point, Double_t *dir, Int_t iact=1, 
                                   Double_t step=0, Double_t *safe=0) const;
   virtual Double_t      DistToSurf(Double_t *point, Double_t *dir) const;
   virtual TGeoVolume   *Divide(TGeoVolume *voldiv, const char *divname, Int_t iaxis, Int_t ndiv, 
                                Double_t start, Double_t step);
   virtual TGeoVolume   *Divide(TGeoVolume *voldiv, const char *divname, Int_t iaxis, Double_t step);
   virtual TGeoShape    *GetMakeRuntimeShape(TGeoShape *mother) const;
   void                  GetVisibleCorner(Double_t *point, Double_t *vertex, Double_t *normals) const;
   void                  GetOppositeCorner(Double_t *point, Int_t inorm, Double_t *vertex, Double_t *normals) const;
   virtual void          InspectShape() const;
   virtual void          Paint(Option_t *option);
   virtual void          NextCrossing(TGeoParamCurve *c, Double_t *point) const;
   virtual Double_t      Safety(Double_t *point, Double_t *spoint, Option_t *option) const;
   virtual void          SetDimensions(Double_t *param);
   virtual void          SetPoints(Double_t *buff) const;
   virtual void          SetPoints(Float_t *buff) const;
   void                  SetVertex(Double_t *vertex) const;
   virtual void          Sizeof3D() const;

  ClassDef(TGeoTrd1, 1)         // TRD1 shape class
};

#endif
