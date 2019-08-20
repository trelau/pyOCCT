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
#include <GeomFill_Profiler.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomFill_SectionGenerator.hxx>

void bind_GeomFill_SectionGenerator(py::module &mod){

py::class_<GeomFill_SectionGenerator, std::unique_ptr<GeomFill_SectionGenerator>, GeomFill_Profiler> cls_GeomFill_SectionGenerator(mod, "GeomFill_SectionGenerator", "gives the functions needed for instantiation from AppSurf in AppBlend. Allow to evaluate a surface passing by all the curves if the Profiler.");

// Constructors
cls_GeomFill_SectionGenerator.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_SectionGenerator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SectionGenerator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SectionGenerator.def_static("operator delete_", (void (*)(void *)) &GeomFill_SectionGenerator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SectionGenerator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SectionGenerator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SectionGenerator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SectionGenerator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SectionGenerator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SectionGenerator.def("SetParam", (void (GeomFill_SectionGenerator::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &GeomFill_SectionGenerator::SetParam, "None", py::arg("Params"));
cls_GeomFill_SectionGenerator.def("GetShape", [](GeomFill_SectionGenerator &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_GeomFill_SectionGenerator.def("Knots", (void (GeomFill_SectionGenerator::*)(TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Knots, "None", py::arg("TKnots"));
cls_GeomFill_SectionGenerator.def("Mults", (void (GeomFill_SectionGenerator::*)(TColStd_Array1OfInteger &) const) &GeomFill_SectionGenerator::Mults, "None", py::arg("TMults"));
cls_GeomFill_SectionGenerator.def("Section", (Standard_Boolean (GeomFill_SectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SectionGenerator.def("Section", (void (GeomFill_SectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_SectionGenerator.def("Parameter", (Standard_Real (GeomFill_SectionGenerator::*)(const Standard_Integer) const) &GeomFill_SectionGenerator::Parameter, "Returns the parameter of Section<P>, to impose it for the approximation.", py::arg("P"));

// Enums

}