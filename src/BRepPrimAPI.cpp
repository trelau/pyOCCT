/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BRepBuilderAPI_MakeShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <BRepPrim_Wedge.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Face.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <BRepPrim_Cone.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrim_Cylinder.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeHalfSpace.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <BRepSweep_Prism.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <gp_Ax1.hxx>
#include <BRepSweep_Revol.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <BRepPrim_Revolution.hxx>
#include <BRepPrimAPI_MakeRevolution.hxx>
#include <BRepPrim_Sphere.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrim_Torus.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>

PYBIND11_MODULE(BRepPrimAPI, mod) {

	// IMPORT
	py::module::import("OCCT.BRepBuilderAPI");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.BRepPrim");
	py::module::import("OCCT.BRepSweep");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeSweep.hxx
	py::class_<BRepPrimAPI_MakeSweep, std::unique_ptr<BRepPrimAPI_MakeSweep, Deleter<BRepPrimAPI_MakeSweep>>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeSweep(mod, "BRepPrimAPI_MakeSweep", "The abstract class MakeSweep is the root class of swept primitives. Sweeps are objects you obtain by sweeping a profile along a path. The profile can be any topology and the path is usually a curve or a wire. The profile generates objects according to the following rules: - Vertices generate Edges - Edges generate Faces. - Wires generate Shells. - Faces generate Solids. - Shells generate Composite Solids. You are not allowed to sweep Solids and Composite Solids. Two kinds of sweeps are implemented in the BRepPrimAPI package: - The linear sweep called a Prism - The rotational sweep called a Revol Swept constructions along complex profiles such as BSpline curves are also available in the BRepOffsetAPI package..");
	cls_BRepPrimAPI_MakeSweep.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeSweep::*)()) &BRepPrimAPI_MakeSweep::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
	cls_BRepPrimAPI_MakeSweep.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeSweep::*)()) &BRepPrimAPI_MakeSweep::LastShape, "Returns the TopoDS Shape of the top of the sweep.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeBox.hxx
	py::class_<BRepPrimAPI_MakeBox, std::unique_ptr<BRepPrimAPI_MakeBox, Deleter<BRepPrimAPI_MakeBox>>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeBox(mod, "BRepPrimAPI_MakeBox", "Describes functions to build parallelepiped boxes. A MakeBox object provides a framework for: - defining the construction of a box, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeBox.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"));
	cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
	cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
	cls_BRepPrimAPI_MakeBox.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
	cls_BRepPrimAPI_MakeBox.def("Wedge", (BRepPrim_Wedge & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Wedge, "Returns the internal algorithm.");
	cls_BRepPrimAPI_MakeBox.def("Build", (void (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Build, "Stores the solid in myShape.");
	cls_BRepPrimAPI_MakeBox.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Shell, "Returns the constructed box as a shell.");
	cls_BRepPrimAPI_MakeBox.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::Solid, "Returns the constructed box as a solid.");
	cls_BRepPrimAPI_MakeBox.def("BottomFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::BottomFace, "Returns ZMin face");
	cls_BRepPrimAPI_MakeBox.def("BackFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::BackFace, "Returns XMin face");
	cls_BRepPrimAPI_MakeBox.def("FrontFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::FrontFace, "Returns XMax face");
	cls_BRepPrimAPI_MakeBox.def("LeftFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::LeftFace, "Returns YMin face");
	cls_BRepPrimAPI_MakeBox.def("RightFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::RightFace, "Returns YMax face");
	cls_BRepPrimAPI_MakeBox.def("TopFace", (const TopoDS_Face & (BRepPrimAPI_MakeBox::*)()) &BRepPrimAPI_MakeBox::TopFace, "Returns ZMax face");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeOneAxis.hxx
	py::class_<BRepPrimAPI_MakeOneAxis, std::unique_ptr<BRepPrimAPI_MakeOneAxis, Deleter<BRepPrimAPI_MakeOneAxis>>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeOneAxis(mod, "BRepPrimAPI_MakeOneAxis", "The abstract class MakeOneAxis is the root class of algorithms used to construct rotational primitives.");
	cls_BRepPrimAPI_MakeOneAxis.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::OneAxis, "The inherited commands should provide the algorithm. Returned as a pointer.");
	cls_BRepPrimAPI_MakeOneAxis.def("Build", (void (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Build, "Stores the solid in myShape.");
	cls_BRepPrimAPI_MakeOneAxis.def("Face", (const TopoDS_Face & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Face, "Returns the lateral face of the rotational primitive.");
	cls_BRepPrimAPI_MakeOneAxis.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Shell, "Returns the constructed rotational primitive as a shell.");
	cls_BRepPrimAPI_MakeOneAxis.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Solid, "Returns the constructed rotational primitive as a solid.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeCone.hxx
	py::class_<BRepPrimAPI_MakeCone, std::unique_ptr<BRepPrimAPI_MakeCone, Deleter<BRepPrimAPI_MakeCone>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeCone(mod, "BRepPrimAPI_MakeCone", "Describes functions to build cones or portions of cones. A MakeCone object provides a framework for: - defining the construction of a cone, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeCone.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("H"));
	cls_BRepPrimAPI_MakeCone.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("H"), py::arg("angle"));
	cls_BRepPrimAPI_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("H"));
	cls_BRepPrimAPI_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("H"), py::arg("angle"));
	cls_BRepPrimAPI_MakeCone.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeCone::*)()) &BRepPrimAPI_MakeCone::OneAxis, "Returns the algorithm.");
	cls_BRepPrimAPI_MakeCone.def("Cone", (BRepPrim_Cone & (BRepPrimAPI_MakeCone::*)()) &BRepPrimAPI_MakeCone::Cone, "Returns the algorithm.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeCylinder.hxx
	py::class_<BRepPrimAPI_MakeCylinder, std::unique_ptr<BRepPrimAPI_MakeCylinder, Deleter<BRepPrimAPI_MakeCylinder>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeCylinder(mod, "BRepPrimAPI_MakeCylinder", "Describes functions to build cylinders or portions of cylinders. A MakeCylinder object provides a framework for: - defining the construction of a cylinder, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeCylinder.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("H"));
	cls_BRepPrimAPI_MakeCylinder.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("H"), py::arg("Angle"));
	cls_BRepPrimAPI_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R"), py::arg("H"));
	cls_BRepPrimAPI_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R"), py::arg("H"), py::arg("Angle"));
	cls_BRepPrimAPI_MakeCylinder.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeCylinder::*)()) &BRepPrimAPI_MakeCylinder::OneAxis, "Returns the algorithm.");
	cls_BRepPrimAPI_MakeCylinder.def("Cylinder", (BRepPrim_Cylinder & (BRepPrimAPI_MakeCylinder::*)()) &BRepPrimAPI_MakeCylinder::Cylinder, "Returns the algorithm.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeHalfSpace.hxx
	py::class_<BRepPrimAPI_MakeHalfSpace, std::unique_ptr<BRepPrimAPI_MakeHalfSpace, Deleter<BRepPrimAPI_MakeHalfSpace>>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeHalfSpace(mod, "BRepPrimAPI_MakeHalfSpace", "Describes functions to build half-spaces. A half-space is an infinite solid, limited by a surface. It is built from a face or a shell, which bounds it, and with a reference point, which specifies the side of the surface where the matter of the half-space is located. A half-space is a tool commonly used in topological operations to cut another shape. A MakeHalfSpace object provides a framework for: - defining and implementing the construction of a half-space, and - consulting the result.");
	cls_BRepPrimAPI_MakeHalfSpace.def(py::init<const TopoDS_Face &, const gp_Pnt &>(), py::arg("Face"), py::arg("RefPnt"));
	cls_BRepPrimAPI_MakeHalfSpace.def(py::init<const TopoDS_Shell &, const gp_Pnt &>(), py::arg("Shell"), py::arg("RefPnt"));
	cls_BRepPrimAPI_MakeHalfSpace.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeHalfSpace::*)() const ) &BRepPrimAPI_MakeHalfSpace::Solid, "Returns the constructed half-space as a solid.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakePrism.hxx
	py::class_<BRepPrimAPI_MakePrism, std::unique_ptr<BRepPrimAPI_MakePrism, Deleter<BRepPrimAPI_MakePrism>>, BRepPrimAPI_MakeSweep> cls_BRepPrimAPI_MakePrism(mod, "BRepPrimAPI_MakePrism", "Describes functions to build linear swept topologies, called prisms. A prism is defined by: - a basis shape, which is swept, and - a sweeping direction, which is: - a vector for finite prisms, or - a direction for infinite or semi-infinite prisms. The basis shape must not contain any solids. The profile generates objects according to the following rules: - Vertices generate Edges - Edges generate Faces. - Wires generate Shells. - Faces generate Solids. - Shells generate Composite Solids A MakePrism object provides a framework for: - defining the construction of a prism, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("S"), py::arg("V"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"), py::arg("Canonize"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &>(), py::arg("S"), py::arg("D"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"));
	cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"), py::arg("Canonize"));
	cls_BRepPrimAPI_MakePrism.def("Prism", (const BRepSweep_Prism & (BRepPrimAPI_MakePrism::*)() const ) &BRepPrimAPI_MakePrism::Prism, "Returns the internal sweeping algorithm.");
	cls_BRepPrimAPI_MakePrism.def("Build", (void (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::Build, "Builds the resulting shape (redefined from MakeShape).");
	cls_BRepPrimAPI_MakePrism.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
	cls_BRepPrimAPI_MakePrism.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::LastShape, "Returns the TopoDS Shape of the top of the prism. In the case of a finite prism, FirstShape returns the basis of the prism, in other words, S if Copy is false; otherwise, the copy of S belonging to the prism. LastShape returns the copy of S translated by V at the time of construction.");
	cls_BRepPrimAPI_MakePrism.def("Generated", (const TopTools_ListOfShape & (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::Generated, "Returns ListOfShape from TopTools.", py::arg("S"));
	cls_BRepPrimAPI_MakePrism.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism. generated with theShape (subShape of the generating shape).", py::arg("theShape"));
	cls_BRepPrimAPI_MakePrism.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with theShape (subShape of the generating shape).", py::arg("theShape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeRevol.hxx
	py::class_<BRepPrimAPI_MakeRevol, std::unique_ptr<BRepPrimAPI_MakeRevol, Deleter<BRepPrimAPI_MakeRevol>>, BRepPrimAPI_MakeSweep> cls_BRepPrimAPI_MakeRevol(mod, "BRepPrimAPI_MakeRevol", "Class to make revolved sweep topologies.");
	cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("S"), py::arg("A"), py::arg("D"));
	cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("D"), py::arg("Copy"));
	cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &>(), py::arg("S"), py::arg("A"));
	cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("Copy"));
	cls_BRepPrimAPI_MakeRevol.def("Revol", (const BRepSweep_Revol & (BRepPrimAPI_MakeRevol::*)() const ) &BRepPrimAPI_MakeRevol::Revol, "Returns the internal sweeping algorithm.");
	cls_BRepPrimAPI_MakeRevol.def("Build", (void (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::Build, "Builds the resulting shape (redefined from MakeShape).");
	cls_BRepPrimAPI_MakeRevol.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).");
	cls_BRepPrimAPI_MakeRevol.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::LastShape, "Returns the TopoDS Shape of the end of the revol.");
	cls_BRepPrimAPI_MakeRevol.def("Generated", (const TopTools_ListOfShape & (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::Generated, "None", py::arg("S"));
	cls_BRepPrimAPI_MakeRevol.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::FirstShape, "Returns the TopoDS Shape of the beginning of the revolution, generated with theShape (subShape of the generating shape).", py::arg("theShape"));
	cls_BRepPrimAPI_MakeRevol.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::LastShape, "Returns the TopoDS Shape of the end of the revolution, generated with theShape (subShape of the generating shape).", py::arg("theShape"));
	cls_BRepPrimAPI_MakeRevol.def("HasDegenerated", (Standard_Boolean (BRepPrimAPI_MakeRevol::*)() const ) &BRepPrimAPI_MakeRevol::HasDegenerated, "Check if there are degenerated edges in the result.");
	cls_BRepPrimAPI_MakeRevol.def("Degenerated", (const TopTools_ListOfShape & (BRepPrimAPI_MakeRevol::*)() const ) &BRepPrimAPI_MakeRevol::Degenerated, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeRevolution.hxx
	py::class_<BRepPrimAPI_MakeRevolution, std::unique_ptr<BRepPrimAPI_MakeRevolution, Deleter<BRepPrimAPI_MakeRevolution>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeRevolution(mod, "BRepPrimAPI_MakeRevolution", "Describes functions to build revolved shapes. A MakeRevolution object provides a framework for: - defining the construction of a revolved shape, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("Meridian"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Meridian"), py::arg("angle"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"), py::arg("angle"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &>(), py::arg("Axes"), py::arg("Meridian"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("angle"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"), py::arg("angle"));
	cls_BRepPrimAPI_MakeRevolution.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeRevolution::*)()) &BRepPrimAPI_MakeRevolution::OneAxis, "Returns the algorithm.");
	cls_BRepPrimAPI_MakeRevolution.def("Revolution", (BRepPrim_Revolution & (BRepPrimAPI_MakeRevolution::*)()) &BRepPrimAPI_MakeRevolution::Revolution, "Returns the algorithm.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeSphere.hxx
	py::class_<BRepPrimAPI_MakeSphere, std::unique_ptr<BRepPrimAPI_MakeSphere, Deleter<BRepPrimAPI_MakeSphere>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeSphere(mod, "BRepPrimAPI_MakeSphere", "Describes functions to build spheres or portions of spheres. A MakeSphere object provides a framework for: - defining the construction of a sphere, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real>(), py::arg("R"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("R"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("Axis"), py::arg("R"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
	cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));
	cls_BRepPrimAPI_MakeSphere.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeSphere::*)()) &BRepPrimAPI_MakeSphere::OneAxis, "Returns the algorithm.");
	cls_BRepPrimAPI_MakeSphere.def("Sphere", (BRepPrim_Sphere & (BRepPrimAPI_MakeSphere::*)()) &BRepPrimAPI_MakeSphere::Sphere, "Returns the algorithm.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeTorus.hxx
	py::class_<BRepPrimAPI_MakeTorus, std::unique_ptr<BRepPrimAPI_MakeTorus, Deleter<BRepPrimAPI_MakeTorus>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeTorus(mod, "BRepPrimAPI_MakeTorus", "Describes functions to build tori or portions of tori. A MakeTorus object provides a framework for: - defining the construction of a torus, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeTorus.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("angle"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("angle1"), py::arg("angle2"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("angle1"), py::arg("angle2"), py::arg("angle"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("angle"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("angle1"), py::arg("angle2"));
	cls_BRepPrimAPI_MakeTorus.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("angle1"), py::arg("angle2"), py::arg("angle"));
	cls_BRepPrimAPI_MakeTorus.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeTorus::*)()) &BRepPrimAPI_MakeTorus::OneAxis, "Returns the algorithm.");
	cls_BRepPrimAPI_MakeTorus.def("Torus", (BRepPrim_Torus & (BRepPrimAPI_MakeTorus::*)()) &BRepPrimAPI_MakeTorus::Torus, "Returns the algorithm.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrimAPI_MakeWedge.hxx
	py::class_<BRepPrimAPI_MakeWedge, std::unique_ptr<BRepPrimAPI_MakeWedge, Deleter<BRepPrimAPI_MakeWedge>>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeWedge(mod, "BRepPrimAPI_MakeWedge", "Describes functions to build wedges, i.e. boxes with inclined faces. A MakeWedge object provides a framework for: - defining the construction of a wedge, - implementing the construction algorithm, and - consulting the result.");
	cls_BRepPrimAPI_MakeWedge.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
	cls_BRepPrimAPI_MakeWedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
	cls_BRepPrimAPI_MakeWedge.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("xmin"), py::arg("zmin"), py::arg("xmax"), py::arg("zmax"));
	cls_BRepPrimAPI_MakeWedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("xmin"), py::arg("zmin"), py::arg("xmax"), py::arg("zmax"));
	cls_BRepPrimAPI_MakeWedge.def("Wedge", (BRepPrim_Wedge & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Wedge, "Returns the internal algorithm.");
	cls_BRepPrimAPI_MakeWedge.def("Build", (void (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Build, "Stores the solid in myShape.");
	cls_BRepPrimAPI_MakeWedge.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Shell, "Returns the constructed box in the form of a shell.");
	cls_BRepPrimAPI_MakeWedge.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Solid, "Returns the constructed box in the form of a solid.");


}
