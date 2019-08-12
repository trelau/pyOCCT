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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <gp_Trsf.hxx>
#include <Geom_BSplineCurve.hxx>
#include <gp_Ax1.hxx>
#include <GeomFill_SequenceOfTrsf.hxx>
#include <GeomFill_SweepSectionGenerator.hxx>

void bind_GeomFill_SweepSectionGenerator(py::module &mod){

py::class_<GeomFill_SweepSectionGenerator, std::unique_ptr<GeomFill_SweepSectionGenerator, Deleter<GeomFill_SweepSectionGenerator>>> cls_GeomFill_SweepSectionGenerator(mod, "GeomFill_SweepSectionGenerator", "class for instantiation of AppBlend. evaluate the sections of a sweep surface.");

// Constructors
cls_GeomFill_SweepSectionGenerator.def(py::init<>());
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
// cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));

// Fields

// Methods
// cls_GeomFill_SweepSectionGenerator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SweepSectionGenerator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete_", (void (*)(void *)) &GeomFill_SweepSectionGenerator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SweepSectionGenerator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SweepSectionGenerator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SweepSectionGenerator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SweepSectionGenerator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
// cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Perform", [](GeomFill_SweepSectionGenerator &self) -> void { return self.Perform(); });
cls_GeomFill_SweepSectionGenerator.def("Perform", (void (GeomFill_SweepSectionGenerator::*)(const Standard_Boolean)) &GeomFill_SweepSectionGenerator::Perform, "None", py::arg("Polynomial"));
cls_GeomFill_SweepSectionGenerator.def("GetShape", [](GeomFill_SweepSectionGenerator &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_GeomFill_SweepSectionGenerator.def("Knots", (void (GeomFill_SweepSectionGenerator::*)(TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Knots, "None", py::arg("TKnots"));
cls_GeomFill_SweepSectionGenerator.def("Mults", (void (GeomFill_SweepSectionGenerator::*)(TColStd_Array1OfInteger &) const) &GeomFill_SweepSectionGenerator::Mults, "None", py::arg("TMults"));
cls_GeomFill_SweepSectionGenerator.def("NbSections", (Standard_Integer (GeomFill_SweepSectionGenerator::*)() const) &GeomFill_SweepSectionGenerator::NbSections, "None");
cls_GeomFill_SweepSectionGenerator.def("Section", (Standard_Boolean (GeomFill_SweepSectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SweepSectionGenerator.def("Section", (void (GeomFill_SweepSectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_SweepSectionGenerator.def("Transformation", (const gp_Trsf & (GeomFill_SweepSectionGenerator::*)(const Standard_Integer) const) &GeomFill_SweepSectionGenerator::Transformation, "raised if <Index> not in the range [1,NbSections()]", py::arg("Index"));
cls_GeomFill_SweepSectionGenerator.def("Parameter", (Standard_Real (GeomFill_SweepSectionGenerator::*)(const Standard_Integer) const) &GeomFill_SweepSectionGenerator::Parameter, "Returns the parameter of <P>, to impose it for the approximation.", py::arg("P"));

// Enums

}