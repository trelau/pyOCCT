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
#include <Standard_Transient.hxx>
#include <GccInt_IType.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Elips2d.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_Bisec.hxx>
#include <Standard_Type.hxx>

void bind_GccInt_Bisec(py::module &mod){

py::class_<GccInt_Bisec, opencascade::handle<GccInt_Bisec>, Standard_Transient> cls_GccInt_Bisec(mod, "GccInt_Bisec", "The deferred class GccInt_Bisec is the root class for elementary bisecting loci between two simple geometric objects (i.e. circles, lines or points). Bisecting loci between two geometric objects are such that each of their points is at the same distance from the two geometric objects. It is typically a curve, such as a line, circle or conic. Generally there is more than one elementary object which is the solution to a bisecting loci problem: each solution is described with one elementary bisecting locus. For example, the bisectors of two secant straight lines are two perpendicular straight lines. The GccInt package provides concrete implementations of the following elementary derived bisecting loci: - lines, circles, ellipses, hyperbolas and parabolas, and - points (not used in this context). The GccAna package provides numerous algorithms for computing the bisecting loci between circles, lines or points, whose solutions are these types of elementary bisecting locus.");

// Fields

// Methods
cls_GccInt_Bisec.def("ArcType", (GccInt_IType (GccInt_Bisec::*)() const) &GccInt_Bisec::ArcType, "Returns the type of bisecting object (line, circle, parabola, hyperbola, ellipse, point).");
cls_GccInt_Bisec.def("Point", (gp_Pnt2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Point, "Returns the bisecting line when ArcType returns Pnt. An exception DomainError is raised if ArcType is not a Pnt.");
cls_GccInt_Bisec.def("Line", (gp_Lin2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Line, "Returns the bisecting line when ArcType returns Lin. An exception DomainError is raised if ArcType is not a Lin.");
cls_GccInt_Bisec.def("Circle", (gp_Circ2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Circle, "Returns the bisecting line when ArcType returns Cir. An exception DomainError is raised if ArcType is not a Cir.");
cls_GccInt_Bisec.def("Hyperbola", (gp_Hypr2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Hyperbola, "Returns the bisecting line when ArcType returns Hpr. An exception DomainError is raised if ArcType is not a Hpr.");
cls_GccInt_Bisec.def("Parabola", (gp_Parab2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Parabola, "Returns the bisecting line when ArcType returns Par. An exception DomainError is raised if ArcType is not a Par.");
cls_GccInt_Bisec.def("Ellipse", (gp_Elips2d (GccInt_Bisec::*)() const) &GccInt_Bisec::Ellipse, "Returns the bisecting line when ArcType returns Ell. An exception DomainError is raised if ArcType is not an Ell.");
cls_GccInt_Bisec.def_static("get_type_name_", (const char * (*)()) &GccInt_Bisec::get_type_name, "None");
cls_GccInt_Bisec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_Bisec::get_type_descriptor, "None");
cls_GccInt_Bisec.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_Bisec::*)() const) &GccInt_Bisec::DynamicType, "None");

// Enums

}