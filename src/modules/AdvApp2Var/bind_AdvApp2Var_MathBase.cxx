/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <AdvApp2Var_MathBase.hxx>

void bind_AdvApp2Var_MathBase(py::module &mod){

py::class_<AdvApp2Var_MathBase> cls_AdvApp2Var_MathBase(mod, "AdvApp2Var_MathBase", "None");

// Constructors

// Fields

// Methods
cls_AdvApp2Var_MathBase.def_static("mmapcmp__", (int (*)(integer *, integer *, integer *, double *, double *)) &AdvApp2Var_MathBase::mmapcmp_, "", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmdrc11__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmdrc11_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmfmca9__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmfmca9_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmfmcb5__", (int (*)(integer *, integer *, integer *, doublereal *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmfmcb5_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmwprcs__", (void (*)(doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_MathBase::mmwprcs_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmcglc1__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmcglc1_, "", py::arg("ndimax"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("courbe"), py::arg("tdebut"), py::arg("tfinal"), py::arg("epsiln"), py::arg("xlongc"), py::arg("erreur"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmbulld__", (int (*)(integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmbulld_, "None", py::arg("nbcoln"), py::arg("nblign"), py::arg("dtabtr"), py::arg("numcle"));
cls_AdvApp2Var_MathBase.def_static("mmcdriv__", (int (*)(integer *, integer *, doublereal *, integer *, integer *, doublereal *)) &AdvApp2Var_MathBase::mmcdriv_, "None", py::arg("ndimen"), py::arg("ncoeff"), py::arg("courbe"), py::arg("ideriv"), py::arg("ncofdv"), py::arg("crvdrv"));
cls_AdvApp2Var_MathBase.def_static("mmcvctx__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmcvctx_, "None", py::arg("ndimen"), py::arg("ncofmx"), py::arg("nderiv"), py::arg("ctrtes"), py::arg("crvres"), py::arg("tabaux"), py::arg("xmatri"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mdsptpt__", (int (*)(integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mdsptpt_, "None", py::arg("ndimen"), py::arg("point1"), py::arg("point2"), py::arg("distan"));
cls_AdvApp2Var_MathBase.def_static("mmaperx__", (int (*)(integer *, integer *, integer *, integer *, doublereal *, integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmaperx_, "None", py::arg("ncofmx"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("iordre"), py::arg("crvjac"), py::arg("ncfnew"), py::arg("ycvmax"), py::arg("errmax"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmdrvck__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmdrvck_, "None", py::arg("ncoeff"), py::arg("ndimen"), py::arg("courbe"), py::arg("ideriv"), py::arg("tparam"), py::arg("pntcrb"));
cls_AdvApp2Var_MathBase.def_static("mmeps1__", (int (*)(doublereal *)) &AdvApp2Var_MathBase::mmeps1_, "None", py::arg("epsilo"));
cls_AdvApp2Var_MathBase.def_static("mmfmca8__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmfmca8_, "None", py::arg("ndimen"), py::arg("ncoefu"), py::arg("ncoefv"), py::arg("ndimax"), py::arg("ncfumx"), py::arg("ncfvmx"), py::arg("tabini"), py::arg("tabres"));
cls_AdvApp2Var_MathBase.def_static("mmfmcar__", (int (*)(integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmfmcar_, "None", py::arg("ndimen"), py::arg("ncofmx"), py::arg("ncoefu"), py::arg("ncoefv"), py::arg("patold"), py::arg("upara1"), py::arg("upara2"), py::arg("vpara1"), py::arg("vpara2"), py::arg("patnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmfmtb1__", (int (*)(integer *, doublereal *, integer *, integer *, integer *, doublereal *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmfmtb1_, "None", py::arg("maxsz1"), py::arg("table1"), py::arg("isize1"), py::arg("jsize1"), py::arg("maxsz2"), py::arg("table2"), py::arg("isize2"), py::arg("jsize2"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmgaus1__", (int (*)(integer *, int (*)(integer *, doublereal *, doublereal *, integer *), integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_MathBase::mmgaus1_, "None", py::arg("ndimf"), py::arg("bfunx"), py::arg("k"), py::arg("xd"), py::arg("xf"), py::arg("saux1"), py::arg("saux2"), py::arg("somme"), py::arg("niter"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmhjcan__", (int (*)(integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmhjcan_, "None", py::arg("ndimen"), py::arg("ncourb"), py::arg("ncftab"), py::arg("orcont"), py::arg("ncflim"), py::arg("tcbold"), py::arg("tdecop"), py::arg("tcbnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mminltt__", (int (*)(integer *, integer *, doublereal *, integer *, integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mminltt_, "None", py::arg("ncolmx"), py::arg("nlgnmx"), py::arg("tabtri"), py::arg("nbrcol"), py::arg("nbrlgn"), py::arg("ajoute"), py::arg("epseg"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmjaccv__", (int (*)(const integer *, const integer *, const integer *, const doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmjaccv_, "None", py::arg("ncoef"), py::arg("ndim"), py::arg("ider"), py::arg("crvlgd"), py::arg("polaux"), py::arg("crvcan"));
cls_AdvApp2Var_MathBase.def_static("mmpobas__", (int (*)(doublereal *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmpobas_, "None", py::arg("tparam"), py::arg("iordre"), py::arg("ncoeff"), py::arg("nderiv"), py::arg("valbas"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmmpocur__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmmpocur_, "None", py::arg("ncofmx"), py::arg("ndim"), py::arg("ndeg"), py::arg("courbe"), py::arg("tparam"), py::arg("tabval"));
cls_AdvApp2Var_MathBase.def_static("mmposui__", (int (*)(integer *, integer *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmposui_, "None", py::arg("dimmat"), py::arg("nistoc"), py::arg("aposit"), py::arg("posuiv"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmresol__", (int (*)(integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmresol_, "None", py::arg("hdimen"), py::arg("gdimen"), py::arg("hnstoc"), py::arg("gnstoc"), py::arg("mnstoc"), py::arg("matsyh"), py::arg("matsyg"), py::arg("vecsyh"), py::arg("vecsyg"), py::arg("hposit"), py::arg("hposui"), py::arg("gposit"), py::arg("mmposui"), py::arg("mposit"), py::arg("vecsol"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmrtptt__", (int (*)(integer *, doublereal *)) &AdvApp2Var_MathBase::mmrtptt_, "None", py::arg("ndglgd"), py::arg("rtlegd"));
cls_AdvApp2Var_MathBase.def_static("mmsrre2__", (int (*)(doublereal *, integer *, doublereal *, doublereal *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmsrre2_, "None", py::arg("tparam"), py::arg("nbrval"), py::arg("tablev"), py::arg("epsil"), py::arg("numint"), py::arg("itypen"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmtrpjj__", (int (*)(integer *, integer *, integer *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmtrpjj_, "None", py::arg("ncofmx"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("epsi3d"), py::arg("iordre"), py::arg("crvlgd"), py::arg("ycvmax"), py::arg("errmax"), py::arg("ncfnew"));
cls_AdvApp2Var_MathBase.def_static("mmunivt__", (int (*)(integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmunivt_, "None", py::arg("ndimen"), py::arg("vector"), py::arg("vecnrm"), py::arg("epsiln"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmvncol__", (int (*)(integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmvncol_, "None", py::arg("ndimen"), py::arg("vecin"), py::arg("vecout"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("msc__", (doublereal (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::msc_, "None", py::arg("ndimen"), py::arg("vecte1"), py::arg("vecte2"));
cls_AdvApp2Var_MathBase.def_static("mvsheld__", (int (*)(integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mvsheld_, "None", py::arg("n"), py::arg("is"), py::arg("dtab"), py::arg("icle"));
cls_AdvApp2Var_MathBase.def_static("mmarcin__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmarcin_, "None", py::arg("ndimax"), py::arg("ndim"), py::arg("ncoeff"), py::arg("crvold"), py::arg("u0"), py::arg("u1"), py::arg("crvnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmcvinv__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmcvinv_, "None", py::arg("ndimax"), py::arg("ncoef"), py::arg("ndim"), py::arg("curveo"), py::arg("curve"));
cls_AdvApp2Var_MathBase.def_static("mmjacan__", (int (*)(const integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmjacan_, "None", py::arg("ideriv"), py::arg("ndeg"), py::arg("poljac"), py::arg("polcan"));
cls_AdvApp2Var_MathBase.def_static("mmpocrb__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmpocrb_, "None", py::arg("ndimax"), py::arg("ncoeff"), py::arg("courbe"), py::arg("ndim"), py::arg("tparam"), py::arg("pntcrb"));
cls_AdvApp2Var_MathBase.def_static("mmmrslwd__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmmrslwd_, "None", py::arg("normax"), py::arg("nordre"), py::arg("ndim"), py::arg("amat"), py::arg("bmat"), py::arg("epspiv"), py::arg("aaux"), py::arg("xmat"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmveps3__", (int (*)(doublereal *)) &AdvApp2Var_MathBase::mmveps3_, "None", py::arg("eps03"));
cls_AdvApp2Var_MathBase.def_static("pow__di_", (doublereal (*)(doublereal *, integer *)) &AdvApp2Var_MathBase::pow__di, "None", py::arg("x"), py::arg("n"));
cls_AdvApp2Var_MathBase.def_static("mzsnorm__", (doublereal (*)(integer *, doublereal *)) &AdvApp2Var_MathBase::mzsnorm_, "None", py::arg("ndimen"), py::arg("vecteu"));

// Enums

}