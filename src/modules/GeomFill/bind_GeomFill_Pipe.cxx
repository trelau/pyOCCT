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
#include <GeomFill_Trihedron.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <gp_Dir.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomAbs_Shape.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomFill_Pipe.hxx>

void bind_GeomFill_Pipe(py::module &mod){

py::class_<GeomFill_Pipe, std::unique_ptr<GeomFill_Pipe>> cls_GeomFill_Pipe(mod, "GeomFill_Pipe", "Describes functions to construct pipes. A pipe is built by sweeping a curve (the section) along another curve (the path). The Pipe class provides the following types of construction: - pipes with a circular section of constant radius, - pipes with a constant section, - pipes with a section evolving between two given curves. All standard specific cases are detected in order to build, where required, a plane, cylinder, cone, sphere, torus, surface of linear extrusion or surface of revolution. Generally speaking, the result is a BSpline surface (NURBS). A Pipe object provides a framework for: - defining the pipe to be built, - implementing the construction algorithm, and - consulting the resulting surface. There are several methods to instantiate a Pipe: 1) give a path and a radius : the section is a circle. This location is the first point of the path, and this direction is the first derivate (calculate at the first point ) of the path.");

// Constructors
cls_GeomFill_Pipe.def(py::init<>());
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const GeomFill_Trihedron>(), py::arg("Path"), py::arg("FirstSect"), py::arg("Option"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("Support"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const gp_Dir &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("Dir"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const TColGeom_SequenceOfCurve &>(), py::arg("Path"), py::arg("NSections"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom_Curve> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Path"), py::arg("Guide"), py::arg("FirstSect"), py::arg("ByACR"), py::arg("rotat"));

// Fields

// Methods
// cls_GeomFill_Pipe.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Pipe::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Pipe.def_static("operator delete_", (void (*)(void *)) &GeomFill_Pipe::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Pipe::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Pipe.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Pipe::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Pipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Pipe::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("Radius"));
cls_GeomFill_Pipe.def("Init", [](GeomFill_Pipe &self, const opencascade::handle<Geom_Curve> & a0, const opencascade::handle<Geom_Curve> & a1) -> void { return self.Init(a0, a1); });
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const GeomFill_Trihedron)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("Option"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("Support"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const gp_Dir &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("Dir"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const TColGeom_SequenceOfCurve &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("NSections"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_Pipe::Init, "Create a pipe with a constant radius with 2 guide-line.", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom_Curve> &, const Standard_Boolean, const Standard_Boolean)) &GeomFill_Pipe::Init, "Initializes this pipe algorithm to build the following surface: - a pipe with a constant circular section of radius Radius along the path Path, or - a pipe with constant section FirstSect along the path Path, or - a pipe where the section evolves from FirstSect to LastSect along the path Path. Use the function Perform to build the surface. Note: a description of the resulting surface is given under Constructors.", py::arg("Path"), py::arg("Guide"), py::arg("FirstSect"), py::arg("ByACR"), py::arg("rotat"));
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self) -> void { return self.Perform(); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Boolean a0) -> void { return self.Perform(a0); });
cls_GeomFill_Pipe.def("Perform", (void (GeomFill_Pipe::*)(const Standard_Boolean, const Standard_Boolean)) &GeomFill_Pipe::Perform, "Builds the pipe defined at the time of initialization of this algorithm. A description of the resulting surface is given under Constructors. If WithParameters (defaulted to false) is set to true, the approximation algorithm (used only in the general case of construction of a BSpline surface) builds the surface with a u parameter corresponding to the one of the path. Exceptions Standard_ConstructionError if a surface cannot be constructed from the data. Warning: It is the old Perform method, the next methode is recommended.", py::arg("WithParameters"), py::arg("myPolynomial"));
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1, const GeomAbs_Shape a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomFill_Pipe.def("Perform", (void (GeomFill_Pipe::*)(const Standard_Real, const Standard_Boolean, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &GeomFill_Pipe::Perform, "detects the particular cases. And compute the surface. if none particular case is detected we make an approximation with respect of the Tolerance <Tol>, the continuty <Conti>, the maximum degree <MaxDegree>, the maximum number of span <NbMaxSegment> and the spine parametrization. If we can't create a surface with the data", py::arg("Tol"), py::arg("Polynomial"), py::arg("Conti"), py::arg("MaxDegree"), py::arg("NbMaxSegment"));
cls_GeomFill_Pipe.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomFill_Pipe::*)() const) &GeomFill_Pipe::Surface, "Returns the surface built by this algorithm. Warning Do not use this function before the surface is built (in this case the function will return a null handle).");
cls_GeomFill_Pipe.def("ExchangeUV", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::ExchangeUV, "The u parametric direction of the surface constructed by this algorithm usually corresponds to the evolution along the path and the v parametric direction corresponds to the evolution along the section(s). However, this rule is not respected when constructing certain specific Geom surfaces (typically cylindrical surfaces, surfaces of revolution, etc.) for which the parameterization is inversed. The ExchangeUV function checks for this, and returns true in all these specific cases. Warning Do not use this function before the surface is built.");
cls_GeomFill_Pipe.def("GenerateParticularCase", (void (GeomFill_Pipe::*)(const Standard_Boolean)) &GeomFill_Pipe::GenerateParticularCase, "Sets a flag to try to create as many planes, cylinder,... as possible. Default value is <Standard_False>.", py::arg("B"));
cls_GeomFill_Pipe.def("GenerateParticularCase", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::GenerateParticularCase, "Returns the flag.");
cls_GeomFill_Pipe.def("ErrorOnSurf", (Standard_Real (GeomFill_Pipe::*)() const) &GeomFill_Pipe::ErrorOnSurf, "Returns the approximation's error. if the Surface is plane, cylinder ... this error can be 0.");
cls_GeomFill_Pipe.def("IsDone", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::IsDone, "Returns whether approximation was done.");

// Enums

}