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
#include <AdvApp2Var_Data.hxx>

void bind_maovpar_1_(py::module &mod){

py::class_<maovpar_1_> cls_maovpar_1_(mod, "maovpar_1_", "None");

// Constructors

// Fields
cls_maovpar_1_.def_readwrite("r8und", &maovpar_1_::r8und, "None");
cls_maovpar_1_.def_readwrite("r8ovr", &maovpar_1_::r8ovr, "None");
cls_maovpar_1_.def_readwrite("x4und", &maovpar_1_::x4und, "None");
cls_maovpar_1_.def_readwrite("x4ovr", &maovpar_1_::x4ovr, "None");
cls_maovpar_1_.def_readwrite("r4und", &maovpar_1_::r4und, "None");
cls_maovpar_1_.def_readwrite("r4ovr", &maovpar_1_::r4ovr, "None");
cls_maovpar_1_.def_readwrite("r4nbe", &maovpar_1_::r4nbe, "None");
cls_maovpar_1_.def_readwrite("r8nbm", &maovpar_1_::r8nbm, "None");
cls_maovpar_1_.def_readwrite("r8nbe", &maovpar_1_::r8nbe, "None");
cls_maovpar_1_.def_readwrite("i4ovr", &maovpar_1_::i4ovr, "None");
cls_maovpar_1_.def_readwrite("i4ovn", &maovpar_1_::i4ovn, "None");
cls_maovpar_1_.def_readwrite("r4exp", &maovpar_1_::r4exp, "None");
cls_maovpar_1_.def_readwrite("r8exp", &maovpar_1_::r8exp, "None");
cls_maovpar_1_.def_readwrite("r4exn", &maovpar_1_::r4exn, "None");
cls_maovpar_1_.def_readwrite("r8exn", &maovpar_1_::r8exn, "None");
cls_maovpar_1_.def_readwrite("r4ncs", &maovpar_1_::r4ncs, "None");
cls_maovpar_1_.def_readwrite("r8ncs", &maovpar_1_::r8ncs, "None");
cls_maovpar_1_.def_readwrite("r4nbm", &maovpar_1_::r4nbm, "None");
cls_maovpar_1_.def_readwrite("i2ovr", &maovpar_1_::i2ovr, "None");
cls_maovpar_1_.def_readwrite("i2ovn", &maovpar_1_::i2ovn, "None");

// Methods

// Enums

}