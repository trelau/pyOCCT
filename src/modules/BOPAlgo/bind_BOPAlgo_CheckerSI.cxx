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
#include <BOPAlgo_PaveFiller.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BOPAlgo_CheckerSI.hxx>

void bind_BOPAlgo_CheckerSI(py::module &mod){

py::class_<BOPAlgo_CheckerSI, std::unique_ptr<BOPAlgo_CheckerSI, Deleter<BOPAlgo_CheckerSI>>, BOPAlgo_PaveFiller> cls_BOPAlgo_CheckerSI(mod, "BOPAlgo_CheckerSI", "Checks the shape on self-interference.");

// Constructors
cls_BOPAlgo_CheckerSI.def(py::init<>());

// Fields

// Methods
// cls_BOPAlgo_CheckerSI.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CheckerSI::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CheckerSI::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CheckerSI::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CheckerSI::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CheckerSI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CheckerSI.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CheckerSI::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CheckerSI.def("Perform", (void (BOPAlgo_CheckerSI::*)()) &BOPAlgo_CheckerSI::Perform, "None");
cls_BOPAlgo_CheckerSI.def("SetLevelOfCheck", (void (BOPAlgo_CheckerSI::*)(const Standard_Integer)) &BOPAlgo_CheckerSI::SetLevelOfCheck, "Sets the level of checking shape on self-interference. It defines which interferences will be checked: 0 - only V/V; 1 - V/V and V/E; 2 - V/V, V/E and E/E; 3 - V/V, V/E, E/E and V/F; 4 - V/V, V/E, E/E, V/F and E/F; 5 - V/V, V/E, E/E, V/F, E/F and F/F; 6 - V/V, V/E, E/E, V/F, E/F, F/F and V/S; 7 - V/V, V/E, E/E, V/F, E/F, F/F, V/S and E/S; 8 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S and F/S; 9 - V/V, V/E, E/E, V/F, E/F, F/F, V/S, E/S, F/S and S/S - all interferences (Default value)", py::arg("theLevel"));

// Enums

}