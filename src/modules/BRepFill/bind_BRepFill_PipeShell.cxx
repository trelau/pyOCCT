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
#include <TopTools_HArray1OfShape.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Dir.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_TypeOfContact.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <GeomFill_PipeError.hxx>
#include <BRepFill_TransitionStyle.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepFill_PipeShell.hxx>
#include <Standard_Type.hxx>
#include <BRepFill_Section.hxx>
#include <gp_Trsf.hxx>
#include <BRepFill_Sweep.hxx>
#include <BRepFill_SequenceOfSection.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFill_LocationLaw.hxx>
#include <BRepFill_SectionLaw.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <GeomFill_Trihedron.hxx>

void bind_BRepFill_PipeShell(py::module &mod){

py::class_<BRepFill_PipeShell, opencascade::handle<BRepFill_PipeShell>, Standard_Transient> cls_BRepFill_PipeShell(mod, "BRepFill_PipeShell", "Computes a topological shell using some wires (spines and profiles) and diplacement option Perform general sweeping construction");

// Constructors
cls_BRepFill_PipeShell.def(py::init<const TopoDS_Wire &>(), py::arg("Spine"));

// Fields

// Methods
cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self) -> void { return self.Set(); });
cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const Standard_Boolean)) &BRepFill_PipeShell::Set, "Set an Frenet or an CorrectedFrenet trihedron to perform the sweeping", py::arg("Frenet"));
cls_BRepFill_PipeShell.def("SetDiscrete", (void (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::SetDiscrete, "Set a Discrete trihedron to perform the sweeping");
cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const gp_Ax2 &)) &BRepFill_PipeShell::Set, "Set an fixed trihedron to perform the sweeping all sections will be parallel.", py::arg("Axe"));
cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const gp_Dir &)) &BRepFill_PipeShell::Set, "Set an fixed BiNormal direction to perform the sweeping", py::arg("BiNormal"));
cls_BRepFill_PipeShell.def("Set", (Standard_Boolean (BRepFill_PipeShell::*)(const TopoDS_Shape &)) &BRepFill_PipeShell::Set, "Set support to the spine to define the BiNormal at the spine, like the normal the surfaces. Warning: To be effective, Each edge of the <spine> must have an representaion on one face of<SpineSupport>", py::arg("SpineSupport"));
cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self, const TopoDS_Wire & a0) -> void { return self.Set(a0); });
cls_BRepFill_PipeShell.def("Set", [](BRepFill_PipeShell &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> void { return self.Set(a0, a1); });
cls_BRepFill_PipeShell.def("Set", (void (BRepFill_PipeShell::*)(const TopoDS_Wire &, const Standard_Boolean, const BRepFill_TypeOfContact)) &BRepFill_PipeShell::Set, "Set an auxiliary spine to define the Normal For each Point of the Spine P, an Point Q is evalued on <AuxiliarySpine> If <CurvilinearEquivalence> Q split <AuxiliarySpine> with the same length ratio than P split <Spline>. Else the plan define by P and the tangent to the <Spine> intersect <AuxiliarySpine> in Q. If <KeepContact> equals BRepFill_NoContact: The Normal is defined by the vector PQ. If <KeepContact> equals BRepFill_Contact: The Normal is defined to achieve that the sweeped section is in contact to the auxiliarySpine. The width of section is constant all along the path. In other words, the auxiliary spine lies on the swept surface, but not necessarily is a boundary of this surface. However, the auxiliary spine has to be close enough to the main spine to provide intersection with any section all along the path. If <KeepContact> equals BRepFill_ContactOnBorder: The auxiliary spine becomes a boundary of the swept surface and the width of section varies along the path.", py::arg("AuxiliarySpine"), py::arg("CurvilinearEquivalence"), py::arg("KeepContact"));
cls_BRepFill_PipeShell.def("SetMaxDegree", (void (BRepFill_PipeShell::*)(const Standard_Integer)) &BRepFill_PipeShell::SetMaxDegree, "Define the maximum V degree of resulting surface", py::arg("NewMaxDegree"));
cls_BRepFill_PipeShell.def("SetMaxSegments", (void (BRepFill_PipeShell::*)(const Standard_Integer)) &BRepFill_PipeShell::SetMaxSegments, "Define the maximum number of spans in V-direction on resulting surface", py::arg("NewMaxSegments"));
cls_BRepFill_PipeShell.def("SetForceApproxC1", (void (BRepFill_PipeShell::*)(const Standard_Boolean)) &BRepFill_PipeShell::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0. Give section to sweep. Possibilities are : - Give one or sevral profile - Give one profile and an homotetic law. - Automatic compute of correspondance beetween profile, and section on the sweeped shape - correspondance beetween profile, and section on the sweeped shape defined by a vertex of the spine", py::arg("ForceApproxC1"));
cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Add(a0, a1); });
cls_BRepFill_PipeShell.def("Add", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::Add, "Set an section. The corespondance with the spine, will be automaticaly performed.", py::arg("Profile"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1) -> void { return self.Add(a0, a1); });
cls_BRepFill_PipeShell.def("Add", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const TopoDS_Vertex & a1, const Standard_Boolean a2) -> void { return self.Add(a0, a1, a2); });
cls_BRepFill_PipeShell.def("Add", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::Add, "Set an section. The corespondance with the spine, is given by <Location>", py::arg("Profile"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1) -> void { return self.SetLaw(a0, a1); });
cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const Standard_Boolean a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepFill_PipeShell.def("SetLaw", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::SetLaw, "Set an section and an homotetic law. The homotetie's centers is given by point on the <Spine>.", py::arg("Profile"), py::arg("L"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2) -> void { return self.SetLaw(a0, a1, a2); });
cls_BRepFill_PipeShell.def("SetLaw", [](BRepFill_PipeShell &self, const TopoDS_Shape & a0, const opencascade::handle<Law_Function> & a1, const TopoDS_Vertex & a2, const Standard_Boolean a3) -> void { return self.SetLaw(a0, a1, a2, a3); });
cls_BRepFill_PipeShell.def("SetLaw", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, const opencascade::handle<Law_Function> &, const TopoDS_Vertex &, const Standard_Boolean, const Standard_Boolean)) &BRepFill_PipeShell::SetLaw, "Set an section and an homotetic law. The homotetie center is given by point on the <Spine>", py::arg("Profile"), py::arg("L"), py::arg("Location"), py::arg("WithContact"), py::arg("WithCorrection"));
cls_BRepFill_PipeShell.def("DeleteProfile", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &)) &BRepFill_PipeShell::DeleteProfile, "Delete an section.", py::arg("Profile"));
cls_BRepFill_PipeShell.def("IsReady", (Standard_Boolean (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::IsReady, "Say if <me> is ready to build the shape return False if <me> do not have section definition");
cls_BRepFill_PipeShell.def("GetStatus", (GeomFill_PipeError (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::GetStatus, "Get a status, when Simulate or Build failed.");
cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self) -> void { return self.SetTolerance(); });
cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_BRepFill_PipeShell.def("SetTolerance", [](BRepFill_PipeShell &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_BRepFill_PipeShell.def("SetTolerance", (void (BRepFill_PipeShell::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_PipeShell::SetTolerance, "None", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("TolAngular"));
cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self) -> void { return self.SetTransition(); });
cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self, const BRepFill_TransitionStyle a0) -> void { return self.SetTransition(a0); });
cls_BRepFill_PipeShell.def("SetTransition", [](BRepFill_PipeShell &self, const BRepFill_TransitionStyle a0, const Standard_Real a1) -> void { return self.SetTransition(a0, a1); });
cls_BRepFill_PipeShell.def("SetTransition", (void (BRepFill_PipeShell::*)(const BRepFill_TransitionStyle, const Standard_Real, const Standard_Real)) &BRepFill_PipeShell::SetTransition, "Set the Transition Mode to manage discontinuities on the sweep.", py::arg("Mode"), py::arg("Angmin"), py::arg("Angmax"));
cls_BRepFill_PipeShell.def("Simulate", (void (BRepFill_PipeShell::*)(const Standard_Integer, TopTools_ListOfShape &)) &BRepFill_PipeShell::Simulate, "Perform simulation of the sweep : Somes Section are returned.", py::arg("NumberOfSection"), py::arg("Sections"));
cls_BRepFill_PipeShell.def("Build", (Standard_Boolean (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepFill_PipeShell.def("MakeSolid", (Standard_Boolean (BRepFill_PipeShell::*)()) &BRepFill_PipeShell::MakeSolid, "Transform the sweeping Shell in Solid. If the section are not closed returns False");
cls_BRepFill_PipeShell.def("Shape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::Shape, "Returns the result Shape.");
cls_BRepFill_PipeShell.def("ErrorOnSurface", (Standard_Real (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::ErrorOnSurface, "None");
cls_BRepFill_PipeShell.def("FirstShape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
cls_BRepFill_PipeShell.def("LastShape", (const TopoDS_Shape & (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::LastShape, "Returns the TopoDS Shape of the top of the sweep.");
cls_BRepFill_PipeShell.def("Profiles", (void (BRepFill_PipeShell::*)(TopTools_ListOfShape &)) &BRepFill_PipeShell::Profiles, "Returns the list of original profiles", py::arg("theProfiles"));
cls_BRepFill_PipeShell.def("Generated", (void (BRepFill_PipeShell::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_PipeShell::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"), py::arg("L"));
cls_BRepFill_PipeShell.def_static("get_type_name_", (const char * (*)()) &BRepFill_PipeShell::get_type_name, "None");
cls_BRepFill_PipeShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_PipeShell::get_type_descriptor, "None");
cls_BRepFill_PipeShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_PipeShell::*)() const) &BRepFill_PipeShell::DynamicType, "None");

// Enums

}