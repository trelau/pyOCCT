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

void bind_mdnombr_1_(py::module &mod){

py::class_<mdnombr_1_, std::unique_ptr<mdnombr_1_>> cls_mdnombr_1_(mod, "mdnombr_1_", "None");

// Constructors

// Fields
cls_mdnombr_1_.def_readwrite("pi", &mdnombr_1_::pi, "None");
cls_mdnombr_1_.def_readwrite("deuxpi", &mdnombr_1_::deuxpi, "None");
cls_mdnombr_1_.def_readwrite("pisur2", &mdnombr_1_::pisur2, "None");
cls_mdnombr_1_.def_readwrite("pis180", &mdnombr_1_::pis180, "None");
cls_mdnombr_1_.def_readwrite("c180pi", &mdnombr_1_::c180pi, "None");
cls_mdnombr_1_.def_readwrite("zero", &mdnombr_1_::zero, "None");
cls_mdnombr_1_.def_readwrite("one", &mdnombr_1_::one, "None");
cls_mdnombr_1_.def_readwrite("a180", &mdnombr_1_::a180, "None");
cls_mdnombr_1_.def_readwrite("a360", &mdnombr_1_::a360, "None");
cls_mdnombr_1_.def_readwrite("a90", &mdnombr_1_::a90, "None");

// Methods

// Enums

}