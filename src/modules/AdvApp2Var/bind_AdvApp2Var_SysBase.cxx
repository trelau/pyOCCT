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
#include <AdvApp2Var_SysBase.hxx>

void bind_AdvApp2Var_SysBase(py::module &mod){

py::class_<AdvApp2Var_SysBase, std::unique_ptr<AdvApp2Var_SysBase>> cls_AdvApp2Var_SysBase(mod, "AdvApp2Var_SysBase", "None");

// Constructors
cls_AdvApp2Var_SysBase.def(py::init<>());

// Fields

// Methods
cls_AdvApp2Var_SysBase.def("mainial_", (int (AdvApp2Var_SysBase::*)()) &AdvApp2Var_SysBase::mainial_, "None");
cls_AdvApp2Var_SysBase.def_static("macinit__", (int (*)(int *, int *)) &AdvApp2Var_SysBase::macinit_, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_SysBase.def("mcrdelt_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, void *, intptr_t *, integer *)) &AdvApp2Var_SysBase::mcrdelt_, "None", py::arg("iunit"), py::arg("isize"), py::arg("t"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("mcrfill__", (int (*)(integer *, void *, void *)) &AdvApp2Var_SysBase::mcrfill_, "None", py::arg("size"), py::arg("tin"), py::arg("tout"));
cls_AdvApp2Var_SysBase.def("mcrrqst_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, void *, intptr_t *, integer *)) &AdvApp2Var_SysBase::mcrrqst_, "None", py::arg("iunit"), py::arg("isize"), py::arg("t"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("mnfndeb__", (integer (*)()) &AdvApp2Var_SysBase::mnfndeb_, "None");
cls_AdvApp2Var_SysBase.def_static("do__fio_", (int (*)()) &AdvApp2Var_SysBase::do__fio, "None");
cls_AdvApp2Var_SysBase.def_static("do__lio_", (int (*)()) &AdvApp2Var_SysBase::do__lio, "None");
cls_AdvApp2Var_SysBase.def("macrai4_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, integer *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrai4_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("itablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrar8_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, doublereal *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrar8_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("xtablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrdi4_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, integer *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrdi4_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("itablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrdr8_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, doublereal *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrdr8_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("xtablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("maermsg__", (int (*)(const char *, integer *, ftnlen)) &AdvApp2Var_SysBase::maermsg_, "None", py::arg("cnompg"), py::arg("icoder"), py::arg("cnompg_len"));
cls_AdvApp2Var_SysBase.def_static("maitbr8__", (int (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_SysBase::maitbr8_, "None", py::arg("itaill"), py::arg("xtab"), py::arg("xval"));
cls_AdvApp2Var_SysBase.def_static("maovsr8__", (int (*)(integer *)) &AdvApp2Var_SysBase::maovsr8_, "None", py::arg("ivalcs"));
cls_AdvApp2Var_SysBase.def_static("mgenmsg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mgenmsg_, "None", py::arg("nomprg"), py::arg("nomprg_len"));
cls_AdvApp2Var_SysBase.def_static("mgsomsg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mgsomsg_, "None", py::arg("nomprg"), py::arg("nomprg_len"));
cls_AdvApp2Var_SysBase.def_static("miraz__", (void (*)(integer *, void *)) &AdvApp2Var_SysBase::miraz_, "None", py::arg("taille"), py::arg("adt"));
cls_AdvApp2Var_SysBase.def_static("msifill__", (int (*)(integer *, integer *, integer *)) &AdvApp2Var_SysBase::msifill_, "None", py::arg("nbintg"), py::arg("ivecin"), py::arg("ivecou"));
cls_AdvApp2Var_SysBase.def_static("msrfill__", (int (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_SysBase::msrfill_, "None", py::arg("nbreel"), py::arg("vecent"), py::arg("vecsor"));
cls_AdvApp2Var_SysBase.def_static("mswrdbg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mswrdbg_, "None", py::arg("ctexte"), py::arg("ctexte_len"));
cls_AdvApp2Var_SysBase.def_static("mvriraz__", (void (*)(integer *, void *)) &AdvApp2Var_SysBase::mvriraz_, "None", py::arg("taille"), py::arg("adt"));

// Enums

}