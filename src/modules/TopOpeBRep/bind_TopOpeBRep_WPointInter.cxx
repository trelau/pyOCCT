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
#include <Standard.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRep_PPntOn2S.hxx>
#include <TopOpeBRep_WPointInter.hxx>

void bind_TopOpeBRep_WPointInter(py::module &mod){

py::class_<TopOpeBRep_WPointInter, std::unique_ptr<TopOpeBRep_WPointInter>> cls_TopOpeBRep_WPointInter(mod, "TopOpeBRep_WPointInter", "None");

// Constructors
cls_TopOpeBRep_WPointInter.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_WPointInter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_WPointInter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_WPointInter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_WPointInter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_WPointInter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_WPointInter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_WPointInter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_WPointInter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_WPointInter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_WPointInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_WPointInter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_WPointInter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_WPointInter.def("Set", (void (TopOpeBRep_WPointInter::*)(const IntSurf_PntOn2S &)) &TopOpeBRep_WPointInter::Set, "None", py::arg("P"));
cls_TopOpeBRep_WPointInter.def("ParametersOnS1", [](TopOpeBRep_WPointInter &self, Standard_Real & U, Standard_Real & V){ self.ParametersOnS1(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_TopOpeBRep_WPointInter.def("ParametersOnS2", [](TopOpeBRep_WPointInter &self, Standard_Real & U, Standard_Real & V){ self.ParametersOnS2(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_TopOpeBRep_WPointInter.def("Parameters", [](TopOpeBRep_WPointInter &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "None", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_TopOpeBRep_WPointInter.def("ValueOnS1", (gp_Pnt2d (TopOpeBRep_WPointInter::*)() const) &TopOpeBRep_WPointInter::ValueOnS1, "None");
cls_TopOpeBRep_WPointInter.def("ValueOnS2", (gp_Pnt2d (TopOpeBRep_WPointInter::*)() const) &TopOpeBRep_WPointInter::ValueOnS2, "None");
cls_TopOpeBRep_WPointInter.def("Value", (const gp_Pnt & (TopOpeBRep_WPointInter::*)() const) &TopOpeBRep_WPointInter::Value, "None");
cls_TopOpeBRep_WPointInter.def("PPntOn2SDummy", (TopOpeBRep_PPntOn2S (TopOpeBRep_WPointInter::*)() const) &TopOpeBRep_WPointInter::PPntOn2SDummy, "None");

// Enums

}