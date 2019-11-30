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
#include <GccInt_IType.hxx>
#include <Standard_Transient.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Elips2d.hxx>
#include <Standard_Std.hxx>
#include <GccInt_Bisec.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <GccInt_BCirc.hxx>
#include <GccInt_BElips.hxx>
#include <GccInt_BHyper.hxx>
#include <GccInt_BLine.hxx>
#include <GccInt_BParab.hxx>
#include <GccInt_BPoint.hxx>

PYBIND11_MODULE(GccInt, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");

// ENUM: GCCINT_ITYPE
py::enum_<GccInt_IType>(mod, "GccInt_IType", "None")
	.value("GccInt_Lin", GccInt_IType::GccInt_Lin)
	.value("GccInt_Cir", GccInt_IType::GccInt_Cir)
	.value("GccInt_Ell", GccInt_IType::GccInt_Ell)
	.value("GccInt_Par", GccInt_IType::GccInt_Par)
	.value("GccInt_Hpr", GccInt_IType::GccInt_Hpr)
	.value("GccInt_Pnt", GccInt_IType::GccInt_Pnt)
	.export_values();


// CLASS: GCCINT_BISEC
py::class_<GccInt_Bisec, opencascade::handle<GccInt_Bisec>, Standard_Transient> cls_GccInt_Bisec(mod, "GccInt_Bisec", "The deferred class GccInt_Bisec is the root class for elementary bisecting loci between two simple geometric objects (i.e. circles, lines or points). Bisecting loci between two geometric objects are such that each of their points is at the same distance from the two geometric objects. It is typically a curve, such as a line, circle or conic. Generally there is more than one elementary object which is the solution to a bisecting loci problem: each solution is described with one elementary bisecting locus. For example, the bisectors of two secant straight lines are two perpendicular straight lines. The GccInt package provides concrete implementations of the following elementary derived bisecting loci: - lines, circles, ellipses, hyperbolas and parabolas, and - points (not used in this context). The GccAna package provides numerous algorithms for computing the bisecting loci between circles, lines or points, whose solutions are these types of elementary bisecting locus.");

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

// CLASS: GCCINT_BCIRC
py::class_<GccInt_BCirc, opencascade::handle<GccInt_BCirc>, GccInt_Bisec> cls_GccInt_BCirc(mod, "GccInt_BCirc", "Describes a circle as a bisecting curve between two 2D geometric objects (such as circles or points).");

// Constructors
cls_GccInt_BCirc.def(py::init<const gp_Circ2d &>(), py::arg("Circ"));

// Methods
cls_GccInt_BCirc.def("Circle", (gp_Circ2d (GccInt_BCirc::*)() const) &GccInt_BCirc::Circle, "Returns a 2D circle which is the geometry of this bisecting curve.");
cls_GccInt_BCirc.def("ArcType", (GccInt_IType (GccInt_BCirc::*)() const) &GccInt_BCirc::ArcType, "Returns GccInt_Cir, which is the type of any GccInt_BCirc bisecting curve.");
cls_GccInt_BCirc.def_static("get_type_name_", (const char * (*)()) &GccInt_BCirc::get_type_name, "None");
cls_GccInt_BCirc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BCirc::get_type_descriptor, "None");
cls_GccInt_BCirc.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BCirc::*)() const) &GccInt_BCirc::DynamicType, "None");

// CLASS: GCCINT_BELIPS
py::class_<GccInt_BElips, opencascade::handle<GccInt_BElips>, GccInt_Bisec> cls_GccInt_BElips(mod, "GccInt_BElips", "Describes an ellipse as a bisecting curve between two 2D geometric objects (such as circles or points).");

// Constructors
cls_GccInt_BElips.def(py::init<const gp_Elips2d &>(), py::arg("Ellipse"));

// Methods
cls_GccInt_BElips.def("Ellipse", (gp_Elips2d (GccInt_BElips::*)() const) &GccInt_BElips::Ellipse, "Returns a 2D ellipse which is the geometry of this bisecting curve.");
cls_GccInt_BElips.def("ArcType", (GccInt_IType (GccInt_BElips::*)() const) &GccInt_BElips::ArcType, "Returns GccInt_Ell, which is the type of any GccInt_BElips bisecting curve.");
cls_GccInt_BElips.def_static("get_type_name_", (const char * (*)()) &GccInt_BElips::get_type_name, "None");
cls_GccInt_BElips.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BElips::get_type_descriptor, "None");
cls_GccInt_BElips.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BElips::*)() const) &GccInt_BElips::DynamicType, "None");

// CLASS: GCCINT_BHYPER
py::class_<GccInt_BHyper, opencascade::handle<GccInt_BHyper>, GccInt_Bisec> cls_GccInt_BHyper(mod, "GccInt_BHyper", "Describes a hyperbola as a bisecting curve between two 2D geometric objects (such as circles or points).");

// Constructors
cls_GccInt_BHyper.def(py::init<const gp_Hypr2d &>(), py::arg("Hyper"));

// Methods
cls_GccInt_BHyper.def("Hyperbola", (gp_Hypr2d (GccInt_BHyper::*)() const) &GccInt_BHyper::Hyperbola, "Returns a 2D hyperbola which is the geometry of this bisecting curve.");
cls_GccInt_BHyper.def("ArcType", (GccInt_IType (GccInt_BHyper::*)() const) &GccInt_BHyper::ArcType, "Returns GccInt_Hpr, which is the type of any GccInt_BHyper bisecting curve.");
cls_GccInt_BHyper.def_static("get_type_name_", (const char * (*)()) &GccInt_BHyper::get_type_name, "None");
cls_GccInt_BHyper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BHyper::get_type_descriptor, "None");
cls_GccInt_BHyper.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BHyper::*)() const) &GccInt_BHyper::DynamicType, "None");

// CLASS: GCCINT_BLINE
py::class_<GccInt_BLine, opencascade::handle<GccInt_BLine>, GccInt_Bisec> cls_GccInt_BLine(mod, "GccInt_BLine", "Describes a line as a bisecting curve between two 2D geometric objects (such as lines, circles or points).");

// Constructors
cls_GccInt_BLine.def(py::init<const gp_Lin2d &>(), py::arg("Line"));

// Methods
cls_GccInt_BLine.def("Line", (gp_Lin2d (GccInt_BLine::*)() const) &GccInt_BLine::Line, "Returns a 2D line which is the geometry of this bisecting line.");
cls_GccInt_BLine.def("ArcType", (GccInt_IType (GccInt_BLine::*)() const) &GccInt_BLine::ArcType, "Returns GccInt_Lin, which is the type of any GccInt_BLine bisecting line.");
cls_GccInt_BLine.def_static("get_type_name_", (const char * (*)()) &GccInt_BLine::get_type_name, "None");
cls_GccInt_BLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BLine::get_type_descriptor, "None");
cls_GccInt_BLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BLine::*)() const) &GccInt_BLine::DynamicType, "None");

// CLASS: GCCINT_BPARAB
py::class_<GccInt_BParab, opencascade::handle<GccInt_BParab>, GccInt_Bisec> cls_GccInt_BParab(mod, "GccInt_BParab", "Describes a parabola as a bisecting curve between two 2D geometric objects (such as lines, circles or points).");

// Constructors
cls_GccInt_BParab.def(py::init<const gp_Parab2d &>(), py::arg("Parab"));

// Methods
cls_GccInt_BParab.def("Parabola", (gp_Parab2d (GccInt_BParab::*)() const) &GccInt_BParab::Parabola, "Returns a 2D parabola which is the geometry of this bisecting curve.");
cls_GccInt_BParab.def("ArcType", (GccInt_IType (GccInt_BParab::*)() const) &GccInt_BParab::ArcType, "Returns GccInt_Par, which is the type of any GccInt_BParab bisecting curve.");
cls_GccInt_BParab.def_static("get_type_name_", (const char * (*)()) &GccInt_BParab::get_type_name, "None");
cls_GccInt_BParab.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BParab::get_type_descriptor, "None");
cls_GccInt_BParab.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BParab::*)() const) &GccInt_BParab::DynamicType, "None");

// CLASS: GCCINT_BPOINT
py::class_<GccInt_BPoint, opencascade::handle<GccInt_BPoint>, GccInt_Bisec> cls_GccInt_BPoint(mod, "GccInt_BPoint", "Describes a point as a bisecting object between two 2D geometric objects.");

// Constructors
cls_GccInt_BPoint.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));

// Methods
cls_GccInt_BPoint.def("Point", (gp_Pnt2d (GccInt_BPoint::*)() const) &GccInt_BPoint::Point, "Returns a 2D point which is the geometry of this bisecting object.");
cls_GccInt_BPoint.def("ArcType", (GccInt_IType (GccInt_BPoint::*)() const) &GccInt_BPoint::ArcType, "Returns GccInt_Pnt, which is the type of any GccInt_BPoint bisecting object.");
cls_GccInt_BPoint.def_static("get_type_name_", (const char * (*)()) &GccInt_BPoint::get_type_name, "None");
cls_GccInt_BPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BPoint::get_type_descriptor, "None");
cls_GccInt_BPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BPoint::*)() const) &GccInt_BPoint::DynamicType, "None");


}
