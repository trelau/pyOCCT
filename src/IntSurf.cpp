#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <IntSurf_Transition.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <IntSurf_Quadric.hxx>
#include <IntSurf_QuadricTool.hxx>
#include <Standard_Transient.hxx>
#include <IntSurf_Allocator.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_Type.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <IntSurf_SequenceOfPntOn2S.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_InteriorPoint.hxx>
#include <IntSurf_SequenceOfInteriorPoint.hxx>
#include <IntSurf_Couple.hxx>
#include <IntSurf_SequenceOfCouple.hxx>
#include <gp_Dir2d.hxx>
#include <IntSurf_PathPoint.hxx>
#include <IntSurf_SequenceOfPathPoint.hxx>
#include <IntSurf_PathPointTool.hxx>
#include <IntSurf_InteriorPointTool.hxx>
#include <gp_Dir.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntSurf.hxx>

PYBIND11_MODULE(IntSurf, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Adaptor3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_TypeTrans.hxx
	py::enum_<IntSurf_TypeTrans>(mod, "IntSurf_TypeTrans", "None")
		.value("IntSurf_In", IntSurf_TypeTrans::IntSurf_In)
		.value("IntSurf_Out", IntSurf_TypeTrans::IntSurf_Out)
		.value("IntSurf_Touch", IntSurf_TypeTrans::IntSurf_Touch)
		.value("IntSurf_Undecided", IntSurf_TypeTrans::IntSurf_Undecided)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_Situation.hxx
	py::enum_<IntSurf_Situation>(mod, "IntSurf_Situation", "None")
		.value("IntSurf_Inside", IntSurf_Situation::IntSurf_Inside)
		.value("IntSurf_Outside", IntSurf_Situation::IntSurf_Outside)
		.value("IntSurf_Unknown", IntSurf_Situation::IntSurf_Unknown)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_PntOn2S.hxx
	py::class_<IntSurf_PntOn2S, std::unique_ptr<IntSurf_PntOn2S, Deleter<IntSurf_PntOn2S>>> cls_IntSurf_PntOn2S(mod, "IntSurf_PntOn2S", "This class defines the geometric informations for an intersection point between 2 surfaces : The coordinates ( Pnt from gp ), and two parametric coordinates.");
	cls_IntSurf_PntOn2S.def(py::init<>());
	cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &)) &IntSurf_PntOn2S::SetValue, "Sets the value of the point in 3d space.", py::arg("Pt"));
	cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of one of the surface.", py::arg("Pt"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of each surface.", py::arg("Pt"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntSurf_PntOn2S.def("Value", (const gp_Pnt & (IntSurf_PntOn2S::*)() const ) &IntSurf_PntOn2S::Value, "Returns the point in 3d space.");
	cls_IntSurf_PntOn2S.def("ValueOnSurface", (gp_Pnt2d (IntSurf_PntOn2S::*)(const Standard_Boolean) const ) &IntSurf_PntOn2S::ValueOnSurface, "Returns the point in 2d space of one of the surfaces.", py::arg("OnFirst"));
	cls_IntSurf_PntOn2S.def("ParametersOnS1", (void (IntSurf_PntOn2S::*)(Standard_Real &, Standard_Real &) const ) &IntSurf_PntOn2S::ParametersOnS1, "Returns the parameters of the point on the first surface.", py::arg("U1"), py::arg("V1"));
	cls_IntSurf_PntOn2S.def("ParametersOnS2", (void (IntSurf_PntOn2S::*)(Standard_Real &, Standard_Real &) const ) &IntSurf_PntOn2S::ParametersOnS2, "Returns the parameters of the point on the second surface.", py::arg("U2"), py::arg("V2"));
	cls_IntSurf_PntOn2S.def("ParametersOnSurface", (void (IntSurf_PntOn2S::*)(const Standard_Boolean, Standard_Real &, Standard_Real &) const ) &IntSurf_PntOn2S::ParametersOnSurface, "Returns the parameters of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PntOn2S.def("Parameters", (void (IntSurf_PntOn2S::*)(Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &) const ) &IntSurf_PntOn2S::Parameters, "Returns the parameters of the point on both surfaces.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0) -> Standard_Boolean { return self.IsSame(a0); }, py::arg("theOtherPoint"));
	cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsSame(a0, a1); }, py::arg("theOtherPoint"), py::arg("theTol3D"));
	cls_IntSurf_PntOn2S.def("IsSame", (Standard_Boolean (IntSurf_PntOn2S::*)(const IntSurf_PntOn2S &, const Standard_Real, const Standard_Real) const ) &IntSurf_PntOn2S::IsSame, "Returns TRUE if 2D- and 3D-coordinates of theOterPoint are equal to corresponding coordinates of me (with given tolerance). If theTol2D < 0.0 we will compare 3D-points only.", py::arg("theOtherPoint"), py::arg("theTol3D"), py::arg("theTol2D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_Transition.hxx
	py::class_<IntSurf_Transition, std::unique_ptr<IntSurf_Transition, Deleter<IntSurf_Transition>>> cls_IntSurf_Transition(mod, "IntSurf_Transition", "Definition of the transition at the intersection between an intersection line and a restriction curve on a surface.");
	cls_IntSurf_Transition.def(py::init<>());
	cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_TypeTrans>(), py::arg("Tangent"), py::arg("Type"));
	cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));
	cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_TypeTrans)) &IntSurf_Transition::SetValue, "Set the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Type"));
	cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean)) &IntSurf_Transition::SetValue, "Set the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));
	cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)()) &IntSurf_Transition::SetValue, "Set the values of an UNDECIDED transition.");
	cls_IntSurf_Transition.def("TransitionType", (IntSurf_TypeTrans (IntSurf_Transition::*)() const ) &IntSurf_Transition::TransitionType, "Returns the type of Transition (in/out/touch/undecided) for the arc given by value. This the transition of the intersection line compared to the Arc of restriction, i-e when the function returns INSIDE for example, it means that the intersection line goes inside the part of plane limited by the arc of restriction.");
	cls_IntSurf_Transition.def("IsTangent", (Standard_Boolean (IntSurf_Transition::*)() const ) &IntSurf_Transition::IsTangent, "Returns TRUE if the point is tangent to the arc given by Value. An exception is raised if TransitionType returns UNDECIDED.");
	cls_IntSurf_Transition.def("Situation", (IntSurf_Situation (IntSurf_Transition::*)() const ) &IntSurf_Transition::Situation, "Returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the intersection line remains inside the Arc, OUTSIDE when it remains outside the Arc, UNKNOWN when the calsulus cannot give results. If TransitionType returns IN, or OUT, or UNDECIDED, a exception is raised.");
	cls_IntSurf_Transition.def("IsOpposite", (Standard_Boolean (IntSurf_Transition::*)() const ) &IntSurf_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, an exception is raised.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_Quadric.hxx
	py::class_<IntSurf_Quadric, std::unique_ptr<IntSurf_Quadric, Deleter<IntSurf_Quadric>>> cls_IntSurf_Quadric(mod, "IntSurf_Quadric", "None");
	cls_IntSurf_Quadric.def(py::init<>());
	cls_IntSurf_Quadric.def(py::init<const gp_Pln &>(), py::arg("P"));
	cls_IntSurf_Quadric.def(py::init<const gp_Cylinder &>(), py::arg("C"));
	cls_IntSurf_Quadric.def(py::init<const gp_Sphere &>(), py::arg("S"));
	cls_IntSurf_Quadric.def(py::init<const gp_Cone &>(), py::arg("C"));
	cls_IntSurf_Quadric.def(py::init<const gp_Torus &>(), py::arg("T"));
	cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Pln &)) &IntSurf_Quadric::SetValue, "None", py::arg("P"));
	cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cylinder &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
	cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Sphere &)) &IntSurf_Quadric::SetValue, "None", py::arg("S"));
	cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Cone &)) &IntSurf_Quadric::SetValue, "None", py::arg("C"));
	cls_IntSurf_Quadric.def("SetValue", (void (IntSurf_Quadric::*)(const gp_Torus &)) &IntSurf_Quadric::SetValue, "None", py::arg("T"));
	cls_IntSurf_Quadric.def("Distance", (Standard_Real (IntSurf_Quadric::*)(const gp_Pnt &) const ) &IntSurf_Quadric::Distance, "None", py::arg("P"));
	cls_IntSurf_Quadric.def("Gradient", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const ) &IntSurf_Quadric::Gradient, "None", py::arg("P"));
	cls_IntSurf_Quadric.def("ValAndGrad", (void (IntSurf_Quadric::*)(const gp_Pnt &, Standard_Real &, gp_Vec &) const ) &IntSurf_Quadric::ValAndGrad, "None", py::arg("P"), py::arg("Dist"), py::arg("Grad"));
	cls_IntSurf_Quadric.def("TypeQuadric", (GeomAbs_SurfaceType (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::TypeQuadric, "None");
	cls_IntSurf_Quadric.def("Plane", (gp_Pln (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::Plane, "None");
	cls_IntSurf_Quadric.def("Sphere", (gp_Sphere (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::Sphere, "None");
	cls_IntSurf_Quadric.def("Cylinder", (gp_Cylinder (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::Cylinder, "None");
	cls_IntSurf_Quadric.def("Cone", (gp_Cone (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::Cone, "None");
	cls_IntSurf_Quadric.def("Torus", (gp_Torus (IntSurf_Quadric::*)() const ) &IntSurf_Quadric::Torus, "None");
	cls_IntSurf_Quadric.def("Value", (gp_Pnt (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const ) &IntSurf_Quadric::Value, "None", py::arg("U"), py::arg("V"));
	cls_IntSurf_Quadric.def("D1", (void (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &IntSurf_Quadric::D1, "None", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
	cls_IntSurf_Quadric.def("DN", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const ) &IntSurf_Quadric::DN, "None", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
	cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const Standard_Real, const Standard_Real) const ) &IntSurf_Quadric::Normale, "None", py::arg("U"), py::arg("V"));
	cls_IntSurf_Quadric.def("Parameters", (void (IntSurf_Quadric::*)(const gp_Pnt &, Standard_Real &, Standard_Real &) const ) &IntSurf_Quadric::Parameters, "None", py::arg("P"), py::arg("U"), py::arg("V"));
	cls_IntSurf_Quadric.def("Normale", (gp_Vec (IntSurf_Quadric::*)(const gp_Pnt &) const ) &IntSurf_Quadric::Normale, "None", py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_QuadricTool.hxx
	py::class_<IntSurf_QuadricTool, std::unique_ptr<IntSurf_QuadricTool, Deleter<IntSurf_QuadricTool>>> cls_IntSurf_QuadricTool(mod, "IntSurf_QuadricTool", "This class provides a tool on a quadric that can be used to instantiates the Walking algorithmes (see package IntWalk) with a Quadric from IntSurf as implicit surface.");
	cls_IntSurf_QuadricTool.def(py::init<>());
	cls_IntSurf_QuadricTool.def_static("Value_", (Standard_Real (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_QuadricTool::Value, "Returns the value of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"));
	cls_IntSurf_QuadricTool.def_static("Gradient_", (void (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &IntSurf_QuadricTool::Gradient, "Returns the gradient of the function.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("V"));
	cls_IntSurf_QuadricTool.def_static("ValueAndGradient_", (void (*)(const IntSurf_Quadric &, const Standard_Real, const Standard_Real, const Standard_Real, Standard_Real &, gp_Vec &)) &IntSurf_QuadricTool::ValueAndGradient, "Returns the value and the gradient.", py::arg("Quad"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Val"), py::arg("Grad"));
	cls_IntSurf_QuadricTool.def_static("Tolerance_", (Standard_Real (*)(const IntSurf_Quadric &)) &IntSurf_QuadricTool::Tolerance, "returns the tolerance of the zero of the implicit function", py::arg("Quad"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_LineOn2S.hxx
	py::class_<IntSurf_LineOn2S, opencascade::handle<IntSurf_LineOn2S>, Standard_Transient> cls_IntSurf_LineOn2S(mod, "IntSurf_LineOn2S", "None");
	cls_IntSurf_LineOn2S.def(py::init<>());
	cls_IntSurf_LineOn2S.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));
	cls_IntSurf_LineOn2S.def("Add", (void (IntSurf_LineOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Add, "Adds a point in the line.", py::arg("P"));
	cls_IntSurf_LineOn2S.def("NbPoints", (Standard_Integer (IntSurf_LineOn2S::*)() const ) &IntSurf_LineOn2S::NbPoints, "Returns the number of points in the line.");
	cls_IntSurf_LineOn2S.def("Value", (const IntSurf_PntOn2S & (IntSurf_LineOn2S::*)(const Standard_Integer) const ) &IntSurf_LineOn2S::Value, "Returns the point of range Index in the line.", py::arg("Index"));
	cls_IntSurf_LineOn2S.def("Reverse", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Reverse, "Reverses the order of points of the line.");
	cls_IntSurf_LineOn2S.def("Split", (opencascade::handle<IntSurf_LineOn2S> (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::Split, "Keeps in <me> the points 1 to Index-1, and returns the items Index to the end.", py::arg("Index"));
	cls_IntSurf_LineOn2S.def("Value", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::Value, "Replaces the point of range Index in the line.", py::arg("Index"), py::arg("P"));
	cls_IntSurf_LineOn2S.def("SetUV", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_LineOn2S::SetUV, "Sets the parametric coordinates on one of the surfaces of the point of range Index in the line.", py::arg("Index"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
	cls_IntSurf_LineOn2S.def("Clear", (void (IntSurf_LineOn2S::*)()) &IntSurf_LineOn2S::Clear, "None");
	cls_IntSurf_LineOn2S.def("InsertBefore", (void (IntSurf_LineOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_LineOn2S::InsertBefore, "None", py::arg("I"), py::arg("P"));
	cls_IntSurf_LineOn2S.def("RemovePoint", (void (IntSurf_LineOn2S::*)(const Standard_Integer)) &IntSurf_LineOn2S::RemovePoint, "None", py::arg("I"));
	cls_IntSurf_LineOn2S.def_static("get_type_name_", (const char * (*)()) &IntSurf_LineOn2S::get_type_name, "None");
	cls_IntSurf_LineOn2S.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntSurf_LineOn2S::get_type_descriptor, "None");
	cls_IntSurf_LineOn2S.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntSurf_LineOn2S::*)() const ) &IntSurf_LineOn2S::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_InteriorPoint.hxx
	py::class_<IntSurf_InteriorPoint, std::unique_ptr<IntSurf_InteriorPoint, Deleter<IntSurf_InteriorPoint>>> cls_IntSurf_InteriorPoint(mod, "IntSurf_InteriorPoint", "Definition of a point solution of the intersection between an implicit an a parametrised surface. These points are passing points on the intersection lines, or starting points for the closed lines on the parametrised surface.");
	cls_IntSurf_InteriorPoint.def(py::init<>());
	cls_IntSurf_InteriorPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));
	cls_IntSurf_InteriorPoint.def("SetValue", (void (IntSurf_InteriorPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &)) &IntSurf_InteriorPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));
	cls_IntSurf_InteriorPoint.def("Value", (const gp_Pnt & (IntSurf_InteriorPoint::*)() const ) &IntSurf_InteriorPoint::Value, "Returns the 3d coordinates of the interior point.");
	cls_IntSurf_InteriorPoint.def("Parameters", (void (IntSurf_InteriorPoint::*)(Standard_Real &, Standard_Real &) const ) &IntSurf_InteriorPoint::Parameters, "Returns the parameters of the interior point on the parametric surface.", py::arg("U"), py::arg("V"));
	cls_IntSurf_InteriorPoint.def("UParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const ) &IntSurf_InteriorPoint::UParameter, "Returns the first parameter of the interior point on the parametric surface.");
	cls_IntSurf_InteriorPoint.def("VParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const ) &IntSurf_InteriorPoint::VParameter, "Returns the second parameter of the interior point on the parametric surface.");
	cls_IntSurf_InteriorPoint.def("Direction", (const gp_Vec & (IntSurf_InteriorPoint::*)() const ) &IntSurf_InteriorPoint::Direction, "Returns the tangent at the intersection in 3d space associated to the interior point.");
	cls_IntSurf_InteriorPoint.def("Direction2d", (const gp_Vec2d & (IntSurf_InteriorPoint::*)() const ) &IntSurf_InteriorPoint::Direction2d, "Returns the tangent at the intersection in the parametric space of the parametric surface.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_Couple.hxx
	py::class_<IntSurf_Couple, std::unique_ptr<IntSurf_Couple, Deleter<IntSurf_Couple>>> cls_IntSurf_Couple(mod, "IntSurf_Couple", "creation d 'un couple de 2 entiers");
	cls_IntSurf_Couple.def(py::init<>());
	cls_IntSurf_Couple.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Index1"), py::arg("Index2"));
	cls_IntSurf_Couple.def("First", (Standard_Integer (IntSurf_Couple::*)() const ) &IntSurf_Couple::First, "returns the first element");
	cls_IntSurf_Couple.def("Second", (Standard_Integer (IntSurf_Couple::*)() const ) &IntSurf_Couple::Second, "returns the Second element");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_PathPoint.hxx
	py::class_<IntSurf_PathPoint, std::unique_ptr<IntSurf_PathPoint, Deleter<IntSurf_PathPoint>>> cls_IntSurf_PathPoint(mod, "IntSurf_PathPoint", "None");
	cls_IntSurf_PathPoint.def(py::init<>());
	cls_IntSurf_PathPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PathPoint.def("SetValue", (void (IntSurf_PathPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PathPoint.def("AddUV", (void (IntSurf_PathPoint::*)(const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::AddUV, "None", py::arg("U"), py::arg("V"));
	cls_IntSurf_PathPoint.def("SetDirections", (void (IntSurf_PathPoint::*)(const gp_Vec &, const gp_Dir2d &)) &IntSurf_PathPoint::SetDirections, "None", py::arg("V"), py::arg("D"));
	cls_IntSurf_PathPoint.def("SetTangency", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetTangency, "None", py::arg("Tang"));
	cls_IntSurf_PathPoint.def("SetPassing", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetPassing, "None", py::arg("Pass"));
	cls_IntSurf_PathPoint.def("Value", (const gp_Pnt & (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::Value, "None");
	cls_IntSurf_PathPoint.def("Value2d", (void (IntSurf_PathPoint::*)(Standard_Real &, Standard_Real &) const ) &IntSurf_PathPoint::Value2d, "None", py::arg("U"), py::arg("V"));
	cls_IntSurf_PathPoint.def("IsPassingPnt", (Standard_Boolean (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::IsPassingPnt, "None");
	cls_IntSurf_PathPoint.def("IsTangent", (Standard_Boolean (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::IsTangent, "None");
	cls_IntSurf_PathPoint.def("Direction3d", (const gp_Vec & (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::Direction3d, "None");
	cls_IntSurf_PathPoint.def("Direction2d", (const gp_Dir2d & (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::Direction2d, "None");
	cls_IntSurf_PathPoint.def("Multiplicity", (Standard_Integer (IntSurf_PathPoint::*)() const ) &IntSurf_PathPoint::Multiplicity, "None");
	cls_IntSurf_PathPoint.def("Parameters", (void (IntSurf_PathPoint::*)(const Standard_Integer, Standard_Real &, Standard_Real &) const ) &IntSurf_PathPoint::Parameters, "None", py::arg("Index"), py::arg("U"), py::arg("V"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_PathPointTool.hxx
	py::class_<IntSurf_PathPointTool, std::unique_ptr<IntSurf_PathPointTool, Deleter<IntSurf_PathPointTool>>> cls_IntSurf_PathPointTool(mod, "IntSurf_PathPointTool", "None");
	cls_IntSurf_PathPointTool.def(py::init<>());
	cls_IntSurf_PathPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("Value2d_", (void (*)(const IntSurf_PathPoint &, Standard_Real &, Standard_Real &)) &IntSurf_PathPointTool::Value2d, "Returns the <U, V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
	cls_IntSurf_PathPointTool.def_static("IsPassingPnt_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsPassingPnt, "Returns True if the point is a point on a non-oriented arc, which means that the intersection line does not stop at such a point but just go through such a point. IsPassingPnt is True when IsOnArc is True", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("IsTangent_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsTangent, "Returns True if the surfaces are tangent at this point. IsTangent can be True when IsOnArc is True if IsPassingPnt is True and IsTangent is True,this point is a stopped point.", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction3d, "returns the tangent at the intersection in 3d space associated to <P> an exception is raised if IsTangent is true.", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction2d, "returns the tangent at the intersection in the parametric space of the parametrized surface.This tangent is associated to the value2d la tangente a un sens signifiant (indique le sens de chemin ement) an exception is raised if IsTangent is true.", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("Multiplicity_", (Standard_Integer (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Multiplicity, "Returns the multiplicity of the point i-e the number of auxillar parameters associated to the point which the principal parameters are given by Value2d", py::arg("PStart"));
	cls_IntSurf_PathPointTool.def_static("Parameters_", (void (*)(const IntSurf_PathPoint &, const Standard_Integer, Standard_Real &, Standard_Real &)) &IntSurf_PathPointTool::Parameters, "Parametric coordinates associated to the multiplicity. An exception is raised if Mult<=0 or Mult>multiplicity.", py::arg("PStart"), py::arg("Mult"), py::arg("U"), py::arg("V"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf_InteriorPointTool.hxx
	py::class_<IntSurf_InteriorPointTool, std::unique_ptr<IntSurf_InteriorPointTool, Deleter<IntSurf_InteriorPointTool>>> cls_IntSurf_InteriorPointTool(mod, "IntSurf_InteriorPointTool", "This class provides a tool on the 'interior point' that can be used to instantiates the Walking algorithmes (see package IntWalk).");
	cls_IntSurf_InteriorPointTool.def(py::init<>());
	cls_IntSurf_InteriorPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
	cls_IntSurf_InteriorPointTool.def_static("Value2d_", (void (*)(const IntSurf_InteriorPoint &, Standard_Real &, Standard_Real &)) &IntSurf_InteriorPointTool::Value2d, "Returns the <U,V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
	cls_IntSurf_InteriorPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction3d, "returns the tangent at the intersectin in 3d space associated to <P>", py::arg("PStart"));
	cls_IntSurf_InteriorPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_InteriorPoint &)) &IntSurf_InteriorPointTool::Direction2d, "returns the tangent at the intersectin in the parametric space of the parametrized surface.This tangent is associated to the value2d", py::arg("PStart"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntSurf.hxx
	py::class_<IntSurf, std::unique_ptr<IntSurf, Deleter<IntSurf>>> cls_IntSurf(mod, "IntSurf", "This package provides resources for all the packages concerning the intersection between surfaces.");
	cls_IntSurf.def(py::init<>());
	cls_IntSurf.def_static("MakeTransition_", (void (*)(const gp_Vec &, const gp_Vec &, const gp_Dir &, IntSurf_Transition &, IntSurf_Transition &)) &IntSurf::MakeTransition, "Computes the transition of the intersection point between the two lines. TgFirst is the tangent vector of the first line. TgSecond is the tangent vector of the second line. Normal is the direction used to orientate the cross product TgFirst^TgSecond. TFirst is the transition of the point on the first line. TSecond is the transition of the point on the second line.", py::arg("TgFirst"), py::arg("TgSecond"), py::arg("Normal"), py::arg("TFirst"), py::arg("TSecond"));
	// FIXME cls_IntSurf.def_static("SetPeriod_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, Standard_Real [4])) &IntSurf::SetPeriod, "Fills theArrOfPeriod array by the period values of theFirstSurf and theSecondSurf. [0] = U-period of theFirstSurf, [1] = V-period of theFirstSurf, [2] = U-period of theSecondSurf, [3] = V-period of theSecondSurf.", py::arg("theFirstSurf"), py::arg("theSecondSurf"), py::arg("theArrOfPeriod"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<IntSurf_ListOfPntOn2S, std::unique_ptr<IntSurf_ListOfPntOn2S, Deleter<IntSurf_ListOfPntOn2S>>, NCollection_BaseList> cls_IntSurf_ListOfPntOn2S(mod, "IntSurf_ListOfPntOn2S", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_IntSurf_ListOfPntOn2S.def(py::init<>());
	cls_IntSurf_ListOfPntOn2S.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntSurf_ListOfPntOn2S.def(py::init([] (const IntSurf_ListOfPntOn2S &other) {return new IntSurf_ListOfPntOn2S(other);}), "Copy constructor", py::arg("other"));
	cls_IntSurf_ListOfPntOn2S.def("begin", (IntSurf_ListOfPntOn2S::iterator (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::begin, "Returns an iterator pointing to the first element in the list.");
	cls_IntSurf_ListOfPntOn2S.def("end", (IntSurf_ListOfPntOn2S::iterator (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_IntSurf_ListOfPntOn2S.def("cbegin", (IntSurf_ListOfPntOn2S::const_iterator (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_IntSurf_ListOfPntOn2S.def("cend", (IntSurf_ListOfPntOn2S::const_iterator (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_IntSurf_ListOfPntOn2S.def("Size", (Standard_Integer (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::Size, "Size - Number of items");
	cls_IntSurf_ListOfPntOn2S.def("Assign", (IntSurf_ListOfPntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_ListOfPntOn2S &)) &IntSurf_ListOfPntOn2S::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntSurf_ListOfPntOn2S.def("assign", (IntSurf_ListOfPntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_ListOfPntOn2S &)) &IntSurf_ListOfPntOn2S::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntSurf_ListOfPntOn2S.def("Clear", [](IntSurf_ListOfPntOn2S &self) -> void { return self.Clear(); });
	cls_IntSurf_ListOfPntOn2S.def("Clear", (void (IntSurf_ListOfPntOn2S::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_ListOfPntOn2S::Clear, "Clear this list", py::arg("theAllocator"));
	cls_IntSurf_ListOfPntOn2S.def("First", (const IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::First, "First item");
	cls_IntSurf_ListOfPntOn2S.def("First", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)()) &IntSurf_ListOfPntOn2S::First, "First item (non-const)");
	cls_IntSurf_ListOfPntOn2S.def("Last", (const IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)() const ) &IntSurf_ListOfPntOn2S::Last, "Last item");
	cls_IntSurf_ListOfPntOn2S.def("Last", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)()) &IntSurf_ListOfPntOn2S::Last, "Last item (non-const)");
	cls_IntSurf_ListOfPntOn2S.def("Append", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_ListOfPntOn2S::Append, "Append one item at the end", py::arg("theItem"));
	cls_IntSurf_ListOfPntOn2S.def("Append", (void (IntSurf_ListOfPntOn2S::*)(const IntSurf_PntOn2S &, IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("Append", (void (IntSurf_ListOfPntOn2S::*)(IntSurf_ListOfPntOn2S &)) &IntSurf_ListOfPntOn2S::Append, "Append another list at the end", py::arg("theOther"));
	cls_IntSurf_ListOfPntOn2S.def("Prepend", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_ListOfPntOn2S::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_IntSurf_ListOfPntOn2S.def("Prepend", (void (IntSurf_ListOfPntOn2S::*)(IntSurf_ListOfPntOn2S &)) &IntSurf_ListOfPntOn2S::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_IntSurf_ListOfPntOn2S.def("RemoveFirst", (void (IntSurf_ListOfPntOn2S::*)()) &IntSurf_ListOfPntOn2S::RemoveFirst, "RemoveFirst item");
	cls_IntSurf_ListOfPntOn2S.def("Remove", (void (IntSurf_ListOfPntOn2S::*)(IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("InsertBefore", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_PntOn2S &, IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("InsertBefore", (void (IntSurf_ListOfPntOn2S::*)(IntSurf_ListOfPntOn2S &, IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("InsertAfter", (IntSurf_PntOn2S & (IntSurf_ListOfPntOn2S::*)(const IntSurf_PntOn2S &, IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("InsertAfter", (void (IntSurf_ListOfPntOn2S::*)(IntSurf_ListOfPntOn2S &, IntSurf_ListOfPntOn2S::Iterator &)) &IntSurf_ListOfPntOn2S::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_IntSurf_ListOfPntOn2S.def("Reverse", (void (IntSurf_ListOfPntOn2S::*)()) &IntSurf_ListOfPntOn2S::Reverse, "Reverse the list");
	cls_IntSurf_ListOfPntOn2S.def("__iter__", [](const IntSurf_ListOfPntOn2S &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<IntSurf_ListIteratorOfListOfPntOn2S, std::unique_ptr<IntSurf_ListIteratorOfListOfPntOn2S, Deleter<IntSurf_ListIteratorOfListOfPntOn2S>>> cls_IntSurf_ListIteratorOfListOfPntOn2S(mod, "IntSurf_ListIteratorOfListOfPntOn2S", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def(py::init<>());
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def("More", (Standard_Boolean (IntSurf_ListIteratorOfListOfPntOn2S::*)() const ) &IntSurf_ListIteratorOfListOfPntOn2S::More, "Check end");
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def("Next", (void (IntSurf_ListIteratorOfListOfPntOn2S::*)()) &IntSurf_ListIteratorOfListOfPntOn2S::Next, "Make step");
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def("Value", (const IntSurf_PntOn2S & (IntSurf_ListIteratorOfListOfPntOn2S::*)() const ) &IntSurf_ListIteratorOfListOfPntOn2S::Value, "Constant Value access");
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def("Value", (IntSurf_PntOn2S & (IntSurf_ListIteratorOfListOfPntOn2S::*)()) &IntSurf_ListIteratorOfListOfPntOn2S::Value, "Non-const Value access");
	cls_IntSurf_ListIteratorOfListOfPntOn2S.def("ChangeValue", (IntSurf_PntOn2S & (IntSurf_ListIteratorOfListOfPntOn2S::*)() const ) &IntSurf_ListIteratorOfListOfPntOn2S::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntSurf_SequenceOfPntOn2S, std::unique_ptr<IntSurf_SequenceOfPntOn2S, Deleter<IntSurf_SequenceOfPntOn2S>>, NCollection_BaseSequence> cls_IntSurf_SequenceOfPntOn2S(mod, "IntSurf_SequenceOfPntOn2S", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntSurf_SequenceOfPntOn2S.def(py::init<>());
	cls_IntSurf_SequenceOfPntOn2S.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntSurf_SequenceOfPntOn2S.def(py::init([] (const IntSurf_SequenceOfPntOn2S &other) {return new IntSurf_SequenceOfPntOn2S(other);}), "Copy constructor", py::arg("other"));
	cls_IntSurf_SequenceOfPntOn2S.def("begin", (IntSurf_SequenceOfPntOn2S::iterator (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfPntOn2S.def("end", (IntSurf_SequenceOfPntOn2S::iterator (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfPntOn2S.def("cbegin", (IntSurf_SequenceOfPntOn2S::const_iterator (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfPntOn2S.def("cend", (IntSurf_SequenceOfPntOn2S::const_iterator (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfPntOn2S.def("Size", (Standard_Integer (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::Size, "Number of items");
	cls_IntSurf_SequenceOfPntOn2S.def("Length", (Standard_Integer (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::Length, "Number of items");
	cls_IntSurf_SequenceOfPntOn2S.def("Lower", (Standard_Integer (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::Lower, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfPntOn2S.def("Upper", (Standard_Integer (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::Upper, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfPntOn2S.def("IsEmpty", (Standard_Boolean (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::IsEmpty, "Empty query");
	cls_IntSurf_SequenceOfPntOn2S.def("Reverse", (void (IntSurf_SequenceOfPntOn2S::*)()) &IntSurf_SequenceOfPntOn2S::Reverse, "Reverse sequence");
	cls_IntSurf_SequenceOfPntOn2S.def("Exchange", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfPntOn2S::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntSurf_SequenceOfPntOn2S.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfPntOn2S::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntSurf_SequenceOfPntOn2S.def("Clear", [](IntSurf_SequenceOfPntOn2S &self) -> void { return self.Clear(); });
	cls_IntSurf_SequenceOfPntOn2S.def("Clear", (void (IntSurf_SequenceOfPntOn2S::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfPntOn2S::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntSurf_SequenceOfPntOn2S.def("Assign", (IntSurf_SequenceOfPntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntSurf_SequenceOfPntOn2S.def("assign", (IntSurf_SequenceOfPntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntSurf_SequenceOfPntOn2S.def("Remove", (void (IntSurf_SequenceOfPntOn2S::*)(IntSurf_SequenceOfPntOn2S::Iterator &)) &IntSurf_SequenceOfPntOn2S::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntSurf_SequenceOfPntOn2S.def("Remove", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer)) &IntSurf_SequenceOfPntOn2S::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("Remove", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfPntOn2S::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("Append", (void (IntSurf_SequenceOfPntOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::Append, "Append one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("Append", (void (IntSurf_SequenceOfPntOn2S::*)(IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfPntOn2S.def("Prepend", (void (IntSurf_SequenceOfPntOn2S::*)(const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("Prepend", (void (IntSurf_SequenceOfPntOn2S::*)(IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfPntOn2S.def("InsertBefore", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("InsertBefore", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPntOn2S.def("InsertAfter", (void (IntSurf_SequenceOfPntOn2S::*)(IntSurf_SequenceOfPntOn2S::Iterator &, const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("InsertAfter", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPntOn2S.def("InsertAfter", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("Split", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, IntSurf_SequenceOfPntOn2S &)) &IntSurf_SequenceOfPntOn2S::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPntOn2S.def("First", (const IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::First, "First item access");
	cls_IntSurf_SequenceOfPntOn2S.def("ChangeFirst", (IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)()) &IntSurf_SequenceOfPntOn2S::ChangeFirst, "First item access");
	cls_IntSurf_SequenceOfPntOn2S.def("Last", (const IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)() const ) &IntSurf_SequenceOfPntOn2S::Last, "Last item access");
	cls_IntSurf_SequenceOfPntOn2S.def("ChangeLast", (IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)()) &IntSurf_SequenceOfPntOn2S::ChangeLast, "Last item access");
	cls_IntSurf_SequenceOfPntOn2S.def("Value", (const IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer) const ) &IntSurf_SequenceOfPntOn2S::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("__call__", (const IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer) const ) &IntSurf_SequenceOfPntOn2S::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("ChangeValue", (IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer)) &IntSurf_SequenceOfPntOn2S::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("__call__", (IntSurf_PntOn2S & (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer)) &IntSurf_SequenceOfPntOn2S::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPntOn2S.def("SetValue", (void (IntSurf_SequenceOfPntOn2S::*)(const Standard_Integer, const IntSurf_PntOn2S &)) &IntSurf_SequenceOfPntOn2S::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPntOn2S.def("__iter__", [](const IntSurf_SequenceOfPntOn2S &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Standard_Handle.hxx
	py::class_<IntSurf_Allocator, std::unique_ptr<IntSurf_Allocator, Deleter<IntSurf_Allocator>>> cls_IntSurf_Allocator(mod, "IntSurf_Allocator", "Intrusive smart pointer for use with Standard_Transient class and its descendants.");
	cls_IntSurf_Allocator.def(py::init<>());
	cls_IntSurf_Allocator.def(py::init<const NCollection_BaseAllocator *>(), py::arg("thePtr"));
	cls_IntSurf_Allocator.def(py::init([] (const handle<NCollection_BaseAllocator> &other) {return new IntSurf_Allocator(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_IntSurf_Allocator.def(py::init<handle<NCollection_BaseAllocator> &&>(), py::arg("theHandle"));
	cls_IntSurf_Allocator.def("Nullify", (void (IntSurf_Allocator::*)()) &IntSurf_Allocator::Nullify, "Nullify the handle");
	cls_IntSurf_Allocator.def("IsNull", (bool (IntSurf_Allocator::*)() const ) &IntSurf_Allocator::IsNull, "Check for being null");
	cls_IntSurf_Allocator.def("reset", (void (IntSurf_Allocator::*)(NCollection_BaseAllocator *)) &IntSurf_Allocator::reset, "Reset by new pointer", py::arg("thePtr"));
	cls_IntSurf_Allocator.def("assign", (handle<NCollection_BaseAllocator> & (IntSurf_Allocator::*)(const handle<NCollection_BaseAllocator> &)) &IntSurf_Allocator::operator=, py::is_operator(), "Assignment operator", py::arg("theHandle"));
	cls_IntSurf_Allocator.def("assign", (handle<NCollection_BaseAllocator> & (IntSurf_Allocator::*)(const NCollection_BaseAllocator *)) &IntSurf_Allocator::operator=, py::is_operator(), "Assignment to pointer", py::arg("thePtr"));
	// FIXME cls_IntSurf_Allocator.def("assign", (handle<NCollection_BaseAllocator> & (IntSurf_Allocator::*)(handle<NCollection_BaseAllocator> &&)) &IntSurf_Allocator::operator=, py::is_operator(), "Move operator", py::arg("theHandle"));
	cls_IntSurf_Allocator.def("get", (NCollection_BaseAllocator * (IntSurf_Allocator::*)() const ) &IntSurf_Allocator::get, "STL-like cast to pointer to referred object (note non-const).");
	// FIXME cls_IntSurf_Allocator.def("operator->", (NCollection_BaseAllocator * (IntSurf_Allocator::*)() const ) &IntSurf_Allocator::operator->, "Member access operator (note non-const)");
	cls_IntSurf_Allocator.def("__mul__", (NCollection_BaseAllocator & (IntSurf_Allocator::*)() const ) &IntSurf_Allocator::operator*, py::is_operator(), "Dereferencing operator (note non-const)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntSurf_SequenceOfInteriorPoint, std::unique_ptr<IntSurf_SequenceOfInteriorPoint, Deleter<IntSurf_SequenceOfInteriorPoint>>, NCollection_BaseSequence> cls_IntSurf_SequenceOfInteriorPoint(mod, "IntSurf_SequenceOfInteriorPoint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntSurf_SequenceOfInteriorPoint.def(py::init<>());
	cls_IntSurf_SequenceOfInteriorPoint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntSurf_SequenceOfInteriorPoint.def(py::init([] (const IntSurf_SequenceOfInteriorPoint &other) {return new IntSurf_SequenceOfInteriorPoint(other);}), "Copy constructor", py::arg("other"));
	cls_IntSurf_SequenceOfInteriorPoint.def("begin", (IntSurf_SequenceOfInteriorPoint::iterator (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfInteriorPoint.def("end", (IntSurf_SequenceOfInteriorPoint::iterator (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfInteriorPoint.def("cbegin", (IntSurf_SequenceOfInteriorPoint::const_iterator (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfInteriorPoint.def("cend", (IntSurf_SequenceOfInteriorPoint::const_iterator (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfInteriorPoint.def("Size", (Standard_Integer (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::Size, "Number of items");
	cls_IntSurf_SequenceOfInteriorPoint.def("Length", (Standard_Integer (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::Length, "Number of items");
	cls_IntSurf_SequenceOfInteriorPoint.def("Lower", (Standard_Integer (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::Lower, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfInteriorPoint.def("Upper", (Standard_Integer (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::Upper, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfInteriorPoint.def("IsEmpty", (Standard_Boolean (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::IsEmpty, "Empty query");
	cls_IntSurf_SequenceOfInteriorPoint.def("Reverse", (void (IntSurf_SequenceOfInteriorPoint::*)()) &IntSurf_SequenceOfInteriorPoint::Reverse, "Reverse sequence");
	cls_IntSurf_SequenceOfInteriorPoint.def("Exchange", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfInteriorPoint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntSurf_SequenceOfInteriorPoint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfInteriorPoint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Clear", [](IntSurf_SequenceOfInteriorPoint &self) -> void { return self.Clear(); });
	cls_IntSurf_SequenceOfInteriorPoint.def("Clear", (void (IntSurf_SequenceOfInteriorPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfInteriorPoint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Assign", (IntSurf_SequenceOfInteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntSurf_SequenceOfInteriorPoint.def("assign", (IntSurf_SequenceOfInteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Remove", (void (IntSurf_SequenceOfInteriorPoint::*)(IntSurf_SequenceOfInteriorPoint::Iterator &)) &IntSurf_SequenceOfInteriorPoint::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Remove", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfInteriorPoint::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Remove", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfInteriorPoint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Append", (void (IntSurf_SequenceOfInteriorPoint::*)(const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Append, "Append one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Append", (void (IntSurf_SequenceOfInteriorPoint::*)(IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Prepend", (void (IntSurf_SequenceOfInteriorPoint::*)(const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Prepend", (void (IntSurf_SequenceOfInteriorPoint::*)(IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfInteriorPoint.def("InsertBefore", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("InsertBefore", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfInteriorPoint.def("InsertAfter", (void (IntSurf_SequenceOfInteriorPoint::*)(IntSurf_SequenceOfInteriorPoint::Iterator &, const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("InsertAfter", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfInteriorPoint.def("InsertAfter", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("Split", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, IntSurf_SequenceOfInteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfInteriorPoint.def("First", (const IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::First, "First item access");
	cls_IntSurf_SequenceOfInteriorPoint.def("ChangeFirst", (IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)()) &IntSurf_SequenceOfInteriorPoint::ChangeFirst, "First item access");
	cls_IntSurf_SequenceOfInteriorPoint.def("Last", (const IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)() const ) &IntSurf_SequenceOfInteriorPoint::Last, "Last item access");
	cls_IntSurf_SequenceOfInteriorPoint.def("ChangeLast", (IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)()) &IntSurf_SequenceOfInteriorPoint::ChangeLast, "Last item access");
	cls_IntSurf_SequenceOfInteriorPoint.def("Value", (const IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer) const ) &IntSurf_SequenceOfInteriorPoint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("__call__", (const IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer) const ) &IntSurf_SequenceOfInteriorPoint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("ChangeValue", (IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfInteriorPoint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("__call__", (IntSurf_InteriorPoint & (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfInteriorPoint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfInteriorPoint.def("SetValue", (void (IntSurf_SequenceOfInteriorPoint::*)(const Standard_Integer, const IntSurf_InteriorPoint &)) &IntSurf_SequenceOfInteriorPoint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfInteriorPoint.def("__iter__", [](const IntSurf_SequenceOfInteriorPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntSurf_SequenceOfCouple, std::unique_ptr<IntSurf_SequenceOfCouple, Deleter<IntSurf_SequenceOfCouple>>, NCollection_BaseSequence> cls_IntSurf_SequenceOfCouple(mod, "IntSurf_SequenceOfCouple", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntSurf_SequenceOfCouple.def(py::init<>());
	cls_IntSurf_SequenceOfCouple.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntSurf_SequenceOfCouple.def(py::init([] (const IntSurf_SequenceOfCouple &other) {return new IntSurf_SequenceOfCouple(other);}), "Copy constructor", py::arg("other"));
	cls_IntSurf_SequenceOfCouple.def("begin", (IntSurf_SequenceOfCouple::iterator (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfCouple.def("end", (IntSurf_SequenceOfCouple::iterator (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfCouple.def("cbegin", (IntSurf_SequenceOfCouple::const_iterator (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfCouple.def("cend", (IntSurf_SequenceOfCouple::const_iterator (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfCouple.def("Size", (Standard_Integer (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::Size, "Number of items");
	cls_IntSurf_SequenceOfCouple.def("Length", (Standard_Integer (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::Length, "Number of items");
	cls_IntSurf_SequenceOfCouple.def("Lower", (Standard_Integer (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::Lower, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfCouple.def("Upper", (Standard_Integer (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::Upper, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfCouple.def("IsEmpty", (Standard_Boolean (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::IsEmpty, "Empty query");
	cls_IntSurf_SequenceOfCouple.def("Reverse", (void (IntSurf_SequenceOfCouple::*)()) &IntSurf_SequenceOfCouple::Reverse, "Reverse sequence");
	cls_IntSurf_SequenceOfCouple.def("Exchange", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfCouple::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntSurf_SequenceOfCouple.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfCouple::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntSurf_SequenceOfCouple.def("Clear", [](IntSurf_SequenceOfCouple &self) -> void { return self.Clear(); });
	cls_IntSurf_SequenceOfCouple.def("Clear", (void (IntSurf_SequenceOfCouple::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfCouple::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntSurf_SequenceOfCouple.def("Assign", (IntSurf_SequenceOfCouple & (IntSurf_SequenceOfCouple::*)(const IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntSurf_SequenceOfCouple.def("assign", (IntSurf_SequenceOfCouple & (IntSurf_SequenceOfCouple::*)(const IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntSurf_SequenceOfCouple.def("Remove", (void (IntSurf_SequenceOfCouple::*)(IntSurf_SequenceOfCouple::Iterator &)) &IntSurf_SequenceOfCouple::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntSurf_SequenceOfCouple.def("Remove", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer)) &IntSurf_SequenceOfCouple::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntSurf_SequenceOfCouple.def("Remove", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfCouple::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntSurf_SequenceOfCouple.def("Append", (void (IntSurf_SequenceOfCouple::*)(const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::Append, "Append one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("Append", (void (IntSurf_SequenceOfCouple::*)(IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfCouple.def("Prepend", (void (IntSurf_SequenceOfCouple::*)(const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("Prepend", (void (IntSurf_SequenceOfCouple::*)(IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfCouple.def("InsertBefore", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("InsertBefore", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfCouple.def("InsertAfter", (void (IntSurf_SequenceOfCouple::*)(IntSurf_SequenceOfCouple::Iterator &, const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("InsertAfter", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfCouple.def("InsertAfter", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("Split", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, IntSurf_SequenceOfCouple &)) &IntSurf_SequenceOfCouple::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfCouple.def("First", (const IntSurf_Couple & (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::First, "First item access");
	cls_IntSurf_SequenceOfCouple.def("ChangeFirst", (IntSurf_Couple & (IntSurf_SequenceOfCouple::*)()) &IntSurf_SequenceOfCouple::ChangeFirst, "First item access");
	cls_IntSurf_SequenceOfCouple.def("Last", (const IntSurf_Couple & (IntSurf_SequenceOfCouple::*)() const ) &IntSurf_SequenceOfCouple::Last, "Last item access");
	cls_IntSurf_SequenceOfCouple.def("ChangeLast", (IntSurf_Couple & (IntSurf_SequenceOfCouple::*)()) &IntSurf_SequenceOfCouple::ChangeLast, "Last item access");
	cls_IntSurf_SequenceOfCouple.def("Value", (const IntSurf_Couple & (IntSurf_SequenceOfCouple::*)(const Standard_Integer) const ) &IntSurf_SequenceOfCouple::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfCouple.def("__call__", (const IntSurf_Couple & (IntSurf_SequenceOfCouple::*)(const Standard_Integer) const ) &IntSurf_SequenceOfCouple::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfCouple.def("ChangeValue", (IntSurf_Couple & (IntSurf_SequenceOfCouple::*)(const Standard_Integer)) &IntSurf_SequenceOfCouple::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfCouple.def("__call__", (IntSurf_Couple & (IntSurf_SequenceOfCouple::*)(const Standard_Integer)) &IntSurf_SequenceOfCouple::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfCouple.def("SetValue", (void (IntSurf_SequenceOfCouple::*)(const Standard_Integer, const IntSurf_Couple &)) &IntSurf_SequenceOfCouple::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfCouple.def("__iter__", [](const IntSurf_SequenceOfCouple &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<IntSurf_SequenceOfPathPoint, std::unique_ptr<IntSurf_SequenceOfPathPoint, Deleter<IntSurf_SequenceOfPathPoint>>, NCollection_BaseSequence> cls_IntSurf_SequenceOfPathPoint(mod, "IntSurf_SequenceOfPathPoint", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_IntSurf_SequenceOfPathPoint.def(py::init<>());
	cls_IntSurf_SequenceOfPathPoint.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_IntSurf_SequenceOfPathPoint.def(py::init([] (const IntSurf_SequenceOfPathPoint &other) {return new IntSurf_SequenceOfPathPoint(other);}), "Copy constructor", py::arg("other"));
	cls_IntSurf_SequenceOfPathPoint.def("begin", (IntSurf_SequenceOfPathPoint::iterator (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfPathPoint.def("end", (IntSurf_SequenceOfPathPoint::iterator (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfPathPoint.def("cbegin", (IntSurf_SequenceOfPathPoint::const_iterator (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_IntSurf_SequenceOfPathPoint.def("cend", (IntSurf_SequenceOfPathPoint::const_iterator (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_IntSurf_SequenceOfPathPoint.def("Size", (Standard_Integer (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::Size, "Number of items");
	cls_IntSurf_SequenceOfPathPoint.def("Length", (Standard_Integer (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::Length, "Number of items");
	cls_IntSurf_SequenceOfPathPoint.def("Lower", (Standard_Integer (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::Lower, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfPathPoint.def("Upper", (Standard_Integer (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::Upper, "Method for consistency with other collections.");
	cls_IntSurf_SequenceOfPathPoint.def("IsEmpty", (Standard_Boolean (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::IsEmpty, "Empty query");
	cls_IntSurf_SequenceOfPathPoint.def("Reverse", (void (IntSurf_SequenceOfPathPoint::*)()) &IntSurf_SequenceOfPathPoint::Reverse, "Reverse sequence");
	cls_IntSurf_SequenceOfPathPoint.def("Exchange", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfPathPoint::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_IntSurf_SequenceOfPathPoint.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfPathPoint::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_IntSurf_SequenceOfPathPoint.def("Clear", [](IntSurf_SequenceOfPathPoint &self) -> void { return self.Clear(); });
	cls_IntSurf_SequenceOfPathPoint.def("Clear", (void (IntSurf_SequenceOfPathPoint::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &IntSurf_SequenceOfPathPoint::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_IntSurf_SequenceOfPathPoint.def("Assign", (IntSurf_SequenceOfPathPoint & (IntSurf_SequenceOfPathPoint::*)(const IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_IntSurf_SequenceOfPathPoint.def("assign", (IntSurf_SequenceOfPathPoint & (IntSurf_SequenceOfPathPoint::*)(const IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_IntSurf_SequenceOfPathPoint.def("Remove", (void (IntSurf_SequenceOfPathPoint::*)(IntSurf_SequenceOfPathPoint::Iterator &)) &IntSurf_SequenceOfPathPoint::Remove, "Remove one item", py::arg("thePosition"));
	cls_IntSurf_SequenceOfPathPoint.def("Remove", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfPathPoint::Remove, "Remove one item", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("Remove", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, const Standard_Integer)) &IntSurf_SequenceOfPathPoint::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("Append", (void (IntSurf_SequenceOfPathPoint::*)(const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::Append, "Append one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("Append", (void (IntSurf_SequenceOfPathPoint::*)(IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfPathPoint.def("Prepend", (void (IntSurf_SequenceOfPathPoint::*)(const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::Prepend, "Prepend one item", py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("Prepend", (void (IntSurf_SequenceOfPathPoint::*)(IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_IntSurf_SequenceOfPathPoint.def("InsertBefore", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("InsertBefore", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPathPoint.def("InsertAfter", (void (IntSurf_SequenceOfPathPoint::*)(IntSurf_SequenceOfPathPoint::Iterator &, const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("InsertAfter", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPathPoint.def("InsertAfter", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("Split", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, IntSurf_SequenceOfPathPoint &)) &IntSurf_SequenceOfPathPoint::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_IntSurf_SequenceOfPathPoint.def("First", (const IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::First, "First item access");
	cls_IntSurf_SequenceOfPathPoint.def("ChangeFirst", (IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)()) &IntSurf_SequenceOfPathPoint::ChangeFirst, "First item access");
	cls_IntSurf_SequenceOfPathPoint.def("Last", (const IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)() const ) &IntSurf_SequenceOfPathPoint::Last, "Last item access");
	cls_IntSurf_SequenceOfPathPoint.def("ChangeLast", (IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)()) &IntSurf_SequenceOfPathPoint::ChangeLast, "Last item access");
	cls_IntSurf_SequenceOfPathPoint.def("Value", (const IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer) const ) &IntSurf_SequenceOfPathPoint::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("__call__", (const IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer) const ) &IntSurf_SequenceOfPathPoint::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("ChangeValue", (IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfPathPoint::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("__call__", (IntSurf_PathPoint & (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer)) &IntSurf_SequenceOfPathPoint::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_IntSurf_SequenceOfPathPoint.def("SetValue", (void (IntSurf_SequenceOfPathPoint::*)(const Standard_Integer, const IntSurf_PathPoint &)) &IntSurf_SequenceOfPathPoint::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_IntSurf_SequenceOfPathPoint.def("__iter__", [](const IntSurf_SequenceOfPathPoint &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
