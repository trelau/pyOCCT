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
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>
#include <AdvApp2Var_ApproxF2var.hxx>

void bind_AdvApp2Var_ApproxF2var(py::module &mod){

py::class_<AdvApp2Var_ApproxF2var, std::unique_ptr<AdvApp2Var_ApproxF2var>> cls_AdvApp2Var_ApproxF2var(mod, "AdvApp2Var_ApproxF2var", "None");

// Constructors

// Fields

// Methods
cls_AdvApp2Var_ApproxF2var.def_static("mma2fnc__", (int (*)(integer *, integer *, integer *, doublereal *, const AdvApp2Var_EvaluatorFunc2Var &, doublereal *, integer *, integer *, doublereal *, integer *, integer *, integer *, integer *, integer *, doublereal *, integer *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2fnc_, "None", py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("uvfonc"), py::arg("foncnp"), py::arg("tconst"), py::arg("isofav"), py::arg("nbroot"), py::arg("rootlg"), py::arg("iordre"), py::arg("ideriv"), py::arg("ndgjac"), py::arg("nbcrmx"), py::arg("ncflim"), py::arg("epsapr"), py::arg("ncoeff"), py::arg("courbe"), py::arg("nbcrbe"), py::arg("somtab"), py::arg("diftab"), py::arg("contr1"), py::arg("contr2"), py::arg("tabdec"), py::arg("errmax"), py::arg("errmoy"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2roo__", (int (*)(integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2roo_, "None", py::arg("nbpntu"), py::arg("nbpntv"), py::arg("urootl"), py::arg("vrootl"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2jmx__", (int (*)(integer *, integer *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2jmx_, "None", py::arg("ndgjac"), py::arg("iordre"), py::arg("xjacmx"));
cls_AdvApp2Var_ApproxF2var.def_static("mmapptt__", (int (*)(const integer *, const integer *, const integer *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mmapptt_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2cdi__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2cdi_, "None", py::arg("ndimen"), py::arg("nbpntu"), py::arg("urootl"), py::arg("nbpntv"), py::arg("vrootl"), py::arg("iordru"), py::arg("iordrv"), py::arg("contr1"), py::arg("contr2"), py::arg("contr3"), py::arg("contr4"), py::arg("sotbu1"), py::arg("sotbu2"), py::arg("ditbu1"), py::arg("ditbu2"), py::arg("sotbv1"), py::arg("sotbv2"), py::arg("ditbv1"), py::arg("ditbv2"), py::arg("sosotb"), py::arg("soditb"), py::arg("disotb"), py::arg("diditb"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ds1__", (int (*)(integer *, doublereal *, doublereal *, const AdvApp2Var_EvaluatorFunc2Var &, integer *, integer *, doublereal *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2ds1_, "None", py::arg("ndimen"), py::arg("uintfn"), py::arg("vintfn"), py::arg("foncnp"), py::arg("nbpntu"), py::arg("nbpntv"), py::arg("urootb"), py::arg("vrootb"), py::arg("isofav"), py::arg("sosotb"), py::arg("disotb"), py::arg("soditb"), py::arg("diditb"), py::arg("fpntab"), py::arg("ttable"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ce1__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *, integer *, integer *)) &AdvApp2Var_ApproxF2var::mma2ce1_, "None", py::arg("numdec"), py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("ndminu"), py::arg("ndminv"), py::arg("ndguli"), py::arg("ndgvli"), py::arg("ndjacu"), py::arg("ndjacv"), py::arg("iordru"), py::arg("iordrv"), py::arg("nbpntu"), py::arg("nbpntv"), py::arg("epsapr"), py::arg("sosotb"), py::arg("disotb"), py::arg("soditb"), py::arg("diditb"), py::arg("patjac"), py::arg("errmax"), py::arg("errmoy"), py::arg("ndegpu"), py::arg("ndegpv"), py::arg("itydec"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2can__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2can_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma1her__", (int (*)(const integer *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma1her_, "None", py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac2__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const integer *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac2_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac3__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const integer *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac3_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac1__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac1_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2fx6__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_ApproxF2var::mma2fx6_, "None", py::arg("ncfmxu"), py::arg("ncfmxv"), py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("nbupat"), py::arg("nbvpat"), py::arg("iordru"), py::arg("iordrv"), py::arg("epsapr"), py::arg("epsfro"), py::arg("patcan"), py::arg("errmax"), py::arg("ncoefu"), py::arg("ncoefv"));

// Enums

}