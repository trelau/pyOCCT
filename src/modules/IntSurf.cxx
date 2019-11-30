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
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <NCollection_List.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntSurf_Transition.hxx>
#include <NCollection_Sequence.hxx>
#include <IntSurf_SequenceOfPntOn2S.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IntSurf_Allocator.hxx>
#include <Standard_Transient.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Bnd_Box2d.hxx>
#include <Bnd_Box.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Ax3.hxx>
#include <gp_Lin.hxx>
#include <IntSurf_Quadric.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <IntSurf_Couple.hxx>
#include <IntSurf_SequenceOfCouple.hxx>
#include <gp_Dir2d.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <IntSurf_PathPoint.hxx>
#include <IntSurf_SequenceOfPathPoint.hxx>
#include <gp_Dir.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntSurf_QuadricTool.hxx>
#include <IntSurf_PathPointTool.hxx>
#include <IntSurf_InteriorPointTool.hxx>
#include <IntSurf.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(IntSurf, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Adaptor3d");

// ENUM: INTSURF_TYPETRANS
py::enum_<IntSurf_TypeTrans>(mod, "IntSurf_TypeTrans", "None")
	.value("IntSurf_In", IntSurf_TypeTrans::IntSurf_In)
	.value("IntSurf_Out", IntSurf_TypeTrans::IntSurf_Out)
	.value("IntSurf_Touch", IntSurf_TypeTrans::IntSurf_Touch)
	.value("IntSurf_Undecided", IntSurf_TypeTrans::IntSurf_Undecided)
	.export_values();


// ENUM: INTSURF_SITUATION
py::enum_<IntSurf_Situation>(mod, "IntSurf_Situation", "None")
	.value("IntSurf_Inside", IntSurf_Situation::IntSurf_Inside)
	.value("IntSurf_Outside", IntSurf_Situation::IntSurf_Outside)
	.value("IntSurf_Unknown", IntSurf_Situation::IntSurf_Unknown)
	.export_values();


// CLASS: INTSURF_PNTON2S
py::class_<IntSurf_PntOn2S> cls_IntSurf_PntOn2S(mod, "IntSurf_PntOn2S", "This class defines the geometric informations for an intersection point between 2 surfaces : The coordinates ( Pnt from gp ), and two parametric coordinates.");

// Constructors
cls_IntSurf_PntOn2S.def(py::init<>());

// Methods
// cls_IntSurf_PntOn2S.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PntOn2S::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PntOn2S.def_static("operator delete_", (void (*)(void *)) &IntSurf_PntOn2S::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PntOn2S::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PntOn2S.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PntOn2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PntOn2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PntOn2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &)) &IntSurf_PntOn2S::SetValue, "Sets the value of the point in 3d space.", py::arg("Pt"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of one of the surface.", py::arg("Pt"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of each surface.", py::arg("Pt"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("Value", (const gp_Pnt & (IntSurf_PntOn2S::*)() const) &IntSurf_PntOn2S::Value, "Returns the point in 3d space.");
cls_IntSurf_PntOn2S.def("ValueOnSurface", (gp_Pnt2d (IntSurf_PntOn2S::*)(const Standard_Boolean) const) &IntSurf_PntOn2S::ValueOnSurface, "Returns the point in 2d space of one of the surfaces.", py::arg("OnFirst"));
cls_IntSurf_PntOn2S.def("ParametersOnS1", [](IntSurf_PntOn2S &self, Standard_Real & U1, Standard_Real & V1){ self.ParametersOnS1(U1, V1); return std::tuple<Standard_Real &, Standard_Real &>(U1, V1); }, "Returns the parameters of the point on the first surface.", py::arg("U1"), py::arg("V1"));
cls_IntSurf_PntOn2S.def("ParametersOnS2", [](IntSurf_PntOn2S &self, Standard_Real & U2, Standard_Real & V2){ self.ParametersOnS2(U2, V2); return std::tuple<Standard_Real &, Standard_Real &>(U2, V2); }, "Returns the parameters of the point on the second surface.", py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("ParametersOnSurface", [](IntSurf_PntOn2S &self, const Standard_Boolean OnFirst, Standard_Real & U, Standard_Real & V){ self.ParametersOnSurface(OnFirst, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("Parameters", [](IntSurf_PntOn2S &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters of the point on both surfaces.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0) -> Standard_Boolean { return self.IsSame(a0); });
cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsSame(a0, a1); });
cls_IntSurf_PntOn2S.def("IsSame", (Standard_Boolean (IntSurf_PntOn2S::*)(const IntSurf_PntOn2S &, const Standard_Real, const Standard_Real) const) &IntSurf_PntOn2S::IsSame, "Returns TRUE if 2D- and 3D-coordinates of theOterPoint are equal to corresponding coordinates of me (with given tolerance). If theTol2D < 0.0 we will compare 3D-points only.", py::arg("theOtherPoint"), py::arg("theTol3D"), py::arg("theTol2D"));

// TYPEDEF: INTSURF_LISTOFPNTON2S
bind_NCollection_List<IntSurf_PntOn2S>(mod, "IntSurf_ListOfPntOn2S", py::module_local(false));

// TYPEDEF: INTSURF_LISTITERATOROFLISTOFPNTON2S
bind_NCollection_TListIterator<IntSurf_PntOn2S>(mod, "IntSurf_ListIteratorOfListOfPntOn2S", py::module_local(false));

// CLASS: INTSURF_TRANSITION
py::class_<IntSurf_Transition> cls_IntSurf_Transition(mod, "IntSurf_Transition", "Definition of the transition at the intersection between an intersection line and a restriction curve on a surface.");

// Constructors
cls_IntSurf_Transition.def(py::init<>());
cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_TypeTrans>(), py::arg("Tangent"), py::arg("Type"));
cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));

// Methods
// cls_IntSurf_Transition.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Transition::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Transition.def_static("operator delete_", (void (*)(void *)) &IntSurf_Transition::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Transition::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Transition.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_TypeTrans)) &IntSurf_Transition::SetValue, "Set the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Type"));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean)) &IntSurf_Transition::SetValue, "Set the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)()) &IntSurf_Transition::SetValue, "Set the values of an UNDECIDED transition.");
cls_IntSurf_Transition.def("TransitionType", (IntSurf_TypeTrans (IntSurf_Transition::*)() const) &IntSurf_Transition::TransitionType, "Returns the type of Transition (in/out/touch/undecided) for the arc given by value. This the transition of the intersection line compared to the Arc of restriction, i-e when the function returns INSIDE for example, it means that the intersection line goes inside the part of plane limited by the arc of restriction.");
cls_IntSurf_Transition.def("IsTangent", (Standard_Boolean (IntSurf_Transition::*)() const) &IntSurf_Transition::IsTangent, "Returns TRUE if the point is tangent to the arc given by Value. An exception is raised if TransitionType returns UNDECIDED.");
cls_IntSurf_Transition.def("Situation", (IntSurf_Situation (IntSurf_Transition::*)() const) &IntSurf_Transition::Situation, "Returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the intersection line remains inside the Arc, OUTSIDE when it remains outside the Arc, UNKNOWN when the calsulus cannot give results. If TransitionType returns IN, or OUT, or UNDECIDED, a exception is raised.");
cls_IntSurf_Transition.def("IsOpposite", (Standard_Boolean (IntSurf_Transition::*)() const) &IntSurf_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, an exception is raised.");

// TYPEDEF: INTSURF_SEQUENCEOFPNTON2S
bind_NCollection_Sequence<IntSurf_PntOn2S>(mod, "IntSurf_SequenceOfPntOn2S", py::module_local(false));

// TYPEDEF: INTSURF_ALLOCATOR
/*
bind_opencascade::handle<NCollection_BaseAllocator>(mod, "IntSurf_Allocator", py::module_local());
*/

// CLASS: INTSURF_LINEON2S
py::class_<IntSurf_LineOn2S, opencascade::handle<IntSurf_LineOn2S>, Standard_Transient> cls_IntSurf_LineOn2S(mod, "IntSurf_LineOn2S", "None");

// Constructors
cls_IntSurf_LineOn2S.def(py::init<>());
cls_IntSurf_LineOn2S.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));

// Methods
cls_IntSurf_LineOn2S.def("Add", (void (IntSurf_LineOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Add, "Adds a point in the line.", py::arg("P"));
cls_IntSurf_LineOn2S.def("NbPoints", (Standard_Integer (IntSurf_LineOn2S::*)() const) &IntSurf_LineOn2S::NbPoints, "Returns the number of points in the line.");
cls_IntSurf_LineOn2S.def("Value", (const IntSurf_PntOn2S & (IntSurf_LineOn2S::*)(const Standard_Integer) const) &IntSurf_LineOn2S::Value, "Returns the point of range Index in the line.", py::arg("Index"));
cls_IntSurf_LineOn2S.def("Reverse", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Reverse, "Reverses the order of points of the line.");
cls_IntSurf_LineOn2S.def("Split", (opencascade::handle<IntSurf_LineOn2S> (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::Split, "Keeps in <me> the points 1 to Index-1, and returns the items Index to the end.", py::arg("Index"));
cls_IntSurf_LineOn2S.def("Value", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Value, "Replaces the point of range Index in the line.", py::arg("Index"), py::arg("P"));
cls_IntSurf_LineOn2S.def("SetUV", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_LineOn2S::SetUV, "Sets the parametric coordinates on one of the surfaces of the point of range Index in the line.", py::arg("Index"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_LineOn2S.def("Clear", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Clear, "None");
cls_IntSurf_LineOn2S.def("InsertBefore", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::InsertBefore, "None", py::arg("I"), py::arg("P"));
cls_IntSurf_LineOn2S.def("RemovePoint", (void (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::RemovePoint, "None", py::arg("I"));
cls_IntSurf_LineOn2S.def("IsOutSurf1Box", (Standard_Boolean (IntSurf_LineOn2S::*)(const gp_Pnt2d &)) &IntSurf_LineOn2S::IsOutSurf1Box, "Returns TRUE if theP is out of the box built from the points on 1st surface", py::arg("theP"));
cls_IntSurf_LineOn2S.def("IsOutSurf2Box", (Standard_Boolean (IntSurf_LineOn2S::*)(const gp_Pnt2d &)) &IntSurf_LineOn2S::IsOutSurf2Box, "Returns TRUE if theP is out of the box built from the points on 2nd surface", py::arg("theP"));
cls_IntSurf_LineOn2S.def("IsOutBox", (Standard_Boolean (IntSurf_LineOn2S::*)(const gp_Pnt &)) &IntSurf_LineOn2S::IsOutBox, "Returns TRUE if theP is out of the box built from 3D-points.", py::arg("theP"));
cls_IntSurf_LineOn2S.def_static("get_type_name_", (const char * (*)()) &IntSurf_LineOn2S::get_type_name, "None");
cls_IntSurf_LineOn2S.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntSurf_LineOn2S::get_type_descriptor, "None");
cls_IntSurf_LineOn2S.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntSurf_LineOn2S::*)() const) &IntSurf_LineOn2S::DynamicType, "None");

// CLASS: INTSURF_QUADRIC
py::class_<IntSurf_Quadric> cls_IntSurf_Quadric(mod, "IntSurf_Quadric", "None");

// Constructors
cls_IntSurf_Quadric.def(py::init<>());
cls_IntSurf_Quadric.def(py::init<const gp_Pln &>(), py::arg("P"));
cls_IntSurf_Quadric.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_IntSurf_Quadric.def(py::init<const gp_Sphere &>(), py::arg("S"));
cls_IntSurf_Quadric.def(py::init<const gp_Cone &>(), py::arg("C"));
cls_IntSurf_Quadric.def(py::init<const gp_Torus &>(), py::arg("T"));

// Methods
// cls_IntSurf_Quadric.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Quadric::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Quadric.def_static("operator delete_", (void (*)(void *)) &IntSurf_Quadric::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Quadric::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Quadric.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Quadric::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Quadric::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Quadric.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Quadric::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Pln &)) &IntSurf_Quadric::SetValue, "None", py::arg("P"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cylinder &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Sphere &)) &IntSurf_Quadric::SetValue, "None", py::arg("S"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cone &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Torus &)) &IntSurf_Quadric::SetValue, "None", py::arg("T"));
cls_IntSurf_Quadric.def("Distance", (Standard_Real (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Distance, "None", py::arg("P"));
cls_IntSurf_Quadric.def("Gradient", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Gradient, "None", py::arg("P"));
cls_IntSurf_Quadric.def("ValAndGrad", [](IntSurf_Quadric &self, const gp_Pnt & P, Standard_Real & Dist, gp_Vec & Grad){ self.ValAndGrad(P, Dist, Grad); return Dist; }, "None", py::arg("P"), py::arg("Dist"), py::arg("Grad"));
cls_IntSurf_Quadric.def("TypeQuadric", (GeomAbs_SurfaceType (IntSurf_Quadric::*)() const) &IntSurf_Quadric::TypeQuadric, "None");
cls_IntSurf_Quadric.def("Plane", (gp_Pln (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Plane, "None");
cls_IntSurf_Quadric.def("Sphere", (gp_Sphere (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Sphere, "None");
cls_IntSurf_Quadric.def("Cylinder", (gp_Cylinder (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Cylinder, "None");
cls_IntSurf_Quadric.def("Cone", (gp_Cone (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Cone, "None");
cls_IntSurf_Quadric.def("Torus", (gp_Torus (IntSurf_Quadric::*)() const) &IntSurf_Quadric::Torus, "None");
cls_IntSurf_Quadric.def("Value", (gp_Pnt (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const) &IntSurf_Quadric::Value, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("D1", (void (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &IntSurf_Quadric::D1, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_IntSurf_Quadric.def("DN", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &IntSurf_Quadric::DN, "None", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const) &IntSurf_Quadric::Normale, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("Parameters", [](IntSurf_Quadric &self, const gp_Pnt & P, Standard_Real & U, Standard_Real & V){ self.Parameters(P, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("P"), py::arg("U"), py::arg("V"));
cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const) &IntSurf_Quadric::Normale, "None", py::arg("P"));

// CLASS: INTSURF_INTERIORPOINT
py::class_<IntSurf_InteriorPoint> cls_IntSurf_InteriorPoint(mod, "IntSurf_InteriorPoint", "Definition of a point solution of the intersection between an implicit an a parametrised surface. These points are passing points on the intersection lines, or starting points for the closed lines on the parametrised surface.");

// Constructors
cls_IntSurf_InteriorPoint.def(py::init<>());
cls_IntSurf_InteriorPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));

// Methods
// cls_IntSurf_InteriorPoint.def_static("operator new_", (void * (*)(size_t)) &IntSurf_InteriorPoint::operator new, "None", py::arg("theSize"));
// cls_IntSurf_InteriorPoint.def_static("operator delete_", (void (*)(void *)) &IntSurf_InteriorPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_InteriorPoint::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_InteriorPoint.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_InteriorPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_InteriorPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_InteriorPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_InteriorPoint.def("SetValue", (void (IntSurf_InteriorPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &)) &IntSurf_InteriorPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));
cls_IntSurf_InteriorPoint.def("Value", (const gp_Pnt & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Value, "Returns the 3d coordinates of the interior point.");
cls_IntSurf_InteriorPoint.def("Parameters", [](IntSurf_InteriorPoint &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters of the interior point on the parametric surface.", py::arg("U"), py::arg("V"));
cls_IntSurf_InteriorPoint.def("UParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::UParameter, "Returns the first parameter of the interior point on the parametric surface.");
cls_IntSurf_InteriorPoint.def("VParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::VParameter, "Returns the second parameter of the interior point on the parametric surface.");
cls_IntSurf_InteriorPoint.def("Direction", (const gp_Vec & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Direction, "Returns the tangent at the intersection in 3d space associated to the interior point.");
cls_IntSurf_InteriorPoint.def("Direction2d", (const gp_Vec2d & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Direction2d, "Returns the tangent at the intersection in the parametric space of the parametric surface.");

// TYPEDEF: INTSURF_SEQUENCEOFINTERIORPOINT
bind_NCollection_Sequence<IntSurf_InteriorPoint>(mod, "IntSurf_SequenceOfInteriorPoint", py::module_local(false));

// CLASS: INTSURF_COUPLE
py::class_<IntSurf_Couple> cls_IntSurf_Couple(mod, "IntSurf_Couple", "creation d 'un couple de 2 entiers");

// Constructors
cls_IntSurf_Couple.def(py::init<>());
cls_IntSurf_Couple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Index1"), py::arg("Index2"));

// Methods
// cls_IntSurf_Couple.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Couple::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Couple.def_static("operator delete_", (void (*)(void *)) &IntSurf_Couple::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Couple::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Couple.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Couple::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Couple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Couple.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Couple::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Couple.def("First", (Standard_Integer (IntSurf_Couple::*)() const) &IntSurf_Couple::First, "returns the first element");
cls_IntSurf_Couple.def("Second", (Standard_Integer (IntSurf_Couple::*)() const) &IntSurf_Couple::Second, "returns the Second element");

// TYPEDEF: INTSURF_SEQUENCEOFCOUPLE
bind_NCollection_Sequence<IntSurf_Couple>(mod, "IntSurf_SequenceOfCouple", py::module_local(false));

// CLASS: INTSURF_PATHPOINT
py::class_<IntSurf_PathPoint> cls_IntSurf_PathPoint(mod, "IntSurf_PathPoint", "None");

// Constructors
cls_IntSurf_PathPoint.def(py::init<>());
cls_IntSurf_PathPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("U"), py::arg("V"));

// Methods
// cls_IntSurf_PathPoint.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PathPoint::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PathPoint.def_static("operator delete_", (void (*)(void *)) &IntSurf_PathPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PathPoint::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PathPoint.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PathPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PathPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PathPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PathPoint.def("SetValue", (void (IntSurf_PathPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("AddUV", (void (IntSurf_PathPoint::*)(const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::AddUV, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("SetDirections", (void (IntSurf_PathPoint::*)(const gp_Vec &, const gp_Dir2d &)) &IntSurf_PathPoint::SetDirections, "None", py::arg("V"), py::arg("D"));
cls_IntSurf_PathPoint.def("SetTangency", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetTangency, "None", py::arg("Tang"));
cls_IntSurf_PathPoint.def("SetPassing", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetPassing, "None", py::arg("Pass"));
cls_IntSurf_PathPoint.def("Value", (const gp_Pnt & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Value, "None");
cls_IntSurf_PathPoint.def("Value2d", [](IntSurf_PathPoint &self, Standard_Real & U, Standard_Real & V){ self.Value2d(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("IsPassingPnt", (Standard_Boolean (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::IsPassingPnt, "None");
cls_IntSurf_PathPoint.def("IsTangent", (Standard_Boolean (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::IsTangent, "None");
cls_IntSurf_PathPoint.def("Direction3d", (const gp_Vec & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Direction3d, "None");
cls_IntSurf_PathPoint.def("Direction2d", (const gp_Dir2d & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Direction2d, "None");
cls_IntSurf_PathPoint.def("Multiplicity", (Standard_Integer (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Multiplicity, "None");
cls_IntSurf_PathPoint.def("Parameters", [](IntSurf_PathPoint &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));

// TYPEDEF: INTSURF_SEQUENCEOFPATHPOINT
bind_NCollection_Sequence<IntSurf_PathPoint>(mod, "IntSurf_SequenceOfPathPoint", py::module_local(false));

// CLASS: INTSURF
py::class_<IntSurf> cls_IntSurf(mod, "IntSurf", "This package provides resources for all the packages concerning the intersection between surfaces.");

// Methods
// cls_IntSurf.def_static("operator new_", (void * (*)(size_t)) &IntSurf::operator new, "None", py::arg("theSize"));
// cls_IntSurf.def_static("operator delete_", (void (*)(void *)) &IntSurf::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf::operator new[], "None", py::arg("theSize"));
// cls_IntSurf.def_static("operator delete[]_", (void (*)(void *)) &IntSurf::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf.def_static("MakeTransition_", (void (*)(const gp_Vec &, const gp_Vec &, const gp_Dir &, IntSurf_Transition &, IntSurf_Transition &)) &IntSurf::MakeTransition, "Computes the transition of the intersection point between the two lines. TgFirst is the tangent vector of the first line. TgSecond is the tangent vector of the second line. Normal is the direction used to orientate the cross product TgFirst^TgSecond. TFirst is the transition of the point on the first line. TSecond is the transition of the point on the second line.", py::arg("TgFirst"), py::arg("TgSecond"), py::arg("Normal"), py::arg("TFirst"), py::arg("TSecond"));
// cls_IntSurf.def_static("SetPeriod_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, Standard_Real [4])) &IntSurf::SetPeriod, "Fills theArrOfPeriod array by the period values of theFirstSurf and theSecondSurf. [0] = U-period of theFirstSurf, [1] = V-period of theFirstSurf, [2] = U-period of theSecondSurf, [3] = V-period of theSecondSurf.", py::arg("theFirstSurf"), py::arg("theSecondSurf"), py::arg("theArrOfPeriod"));

// CLASS: INTSURF_INTERIORPOINTTOOL
py::class_<IntSurf_InteriorPointTool> cls_IntSurf_InteriorPointTool(mod, "IntSurf_InteriorPointTool", "This class provides a tool on the 'interior point' that can be used to instantiates the Walking algorithmes (see package IntWalk).");

// Methods
// cls_IntSurf_InteriorPointTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_InteriorPointTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_InteriorPointTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_InteriorPointTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_InteriorPointTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_InteriorPointTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_InteriorPointTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_InteriorPointTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_InteriorPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
cls_IntSurf_InteriorPointTool.def_static("Value2d_", [](const IntSurf_InteriorPoint & PStart, Standard_Real & U, Standard_Real & V){ IntSurf_InteriorPointTool::Value2d(PStart, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the <U,V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
cls_IntSurf_InteriorPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction3d, "returns the tangent at the intersectin in 3d space associated to <P>", py::arg("PStart"));
cls_IntSurf_InteriorPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction2d, "returns the tangent at the intersectin in the parametric space of the parametrized surface.This tangent is associated to the value2d", py::arg("PStart"));

// CLASS: INTSURF_PATHPOINTTOOL
py::class_<IntSurf_PathPointTool> cls_IntSurf_PathPointTool(mod, "IntSurf_PathPointTool", "None");

// Methods
// cls_IntSurf_PathPointTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PathPointTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PathPointTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_PathPointTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PathPointTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PathPointTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PathPointTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PathPointTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PathPointTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PathPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Value2d_", [](const IntSurf_PathPoint & PStart, Standard_Real & U, Standard_Real & V){ IntSurf_PathPointTool::Value2d(PStart, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the <U, V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
cls_IntSurf_PathPointTool.def_static("IsPassingPnt_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsPassingPnt, "Returns True if the point is a point on a non-oriented arc, which means that the intersection line does not stop at such a point but just go through such a point. IsPassingPnt is True when IsOnArc is True", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("IsTangent_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsTangent, "Returns True if the surfaces are tangent at this point. IsTangent can be True when IsOnArc is True if IsPassingPnt is True and IsTangent is True,this point is a stopped point.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction3d, "returns the tangent at the intersection in 3d space associated to <P> an exception is raised if IsTangent is true.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction2d, "returns the tangent at the intersection in the parametric space of the parametrized surface.This tangent is associated to the value2d la tangente a un sens signifiant (indique le sens de chemin ement) an exception is raised if IsTangent is true.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Multiplicity_", (Standard_Integer (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Multiplicity, "Returns the multiplicity of the point i-e the number of auxillar parameters associated to the point which the principal parameters are given by Value2d", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Parameters_", [](const IntSurf_PathPoint & PStart, const Standard_Integer Mult, Standard_Real & U, Standard_Real & V){ IntSurf_PathPointTool::Parameters(PStart, Mult, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Parametric coordinates associated to the multiplicity. An exception is raised if Mult<=0 or Mult>multiplicity.", py::arg("PStart"), py::arg("Mult"), py::arg("U"), py::arg("V"));

// CLASS: INTSURF_QUADRICTOOL
py::class_<IntSurf_QuadricTool> cls_IntSurf_QuadricTool(mod, "IntSurf_QuadricTool", "This class provides a tool on a quadric that can be used to instantiates the Walking algorithmes (see package IntWalk) with a Quadric from IntSurf as implicit surface.");

// Methods
// cls_IntSurf_QuadricTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_QuadricTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_QuadricTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_QuadricTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_QuadricTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_QuadricTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_QuadricTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_QuadricTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_QuadricTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_QuadricTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_QuadricTool.def_static("Value_", (Standard_Real (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_QuadricTool::Value, "Returns the value of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_IntSurf_QuadricTool.def_static("Gradient_", (void (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &IntSurf_QuadricTool::Gradient, "Returns the gradient of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("V"));
cls_IntSurf_QuadricTool.def_static("ValueAndGradient_", [](const IntSurf_Quadric & Quad, const Standard_Real X, const Standard_Real Y, const Standard_Real Z, Standard_Real & Val, gp_Vec & Grad){ IntSurf_QuadricTool::ValueAndGradient(Quad, X, Y, Z, Val, Grad); return Val; }, "Returns the value and the gradient.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Val"), py::arg("Grad"));
cls_IntSurf_QuadricTool.def_static("Tolerance_", (Standard_Real (*)(const IntSurf_Quadric &)) &IntSurf_QuadricTool::Tolerance, "returns the tolerance of the zero of the implicit function", py::arg("Quad"));


}
