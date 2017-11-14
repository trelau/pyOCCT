#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <IntWalk_VectorOfWalkingData.hxx>
#include <IntWalk_VectorOfInteger.hxx>
#include <IntWalk_StatusDeflection.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <IntImp_ConstIsoparametric.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <IntWalk_TheFunctionOfTheInt2S.hxx>
#include <math_FunctionSetRoot.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntWalk_TheInt2S.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntWalk_PWalking.hxx>

PYBIND11_MODULE(IntWalk, mod) {

	// IMPORT
	py::module::import("OCCT.math");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.IntImp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.IntSurf");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntWalk_StatusDeflection.hxx
	py::enum_<IntWalk_StatusDeflection>(mod, "IntWalk_StatusDeflection", "None")
		.value("IntWalk_PasTropGrand", IntWalk_StatusDeflection::IntWalk_PasTropGrand)
		.value("IntWalk_StepTooSmall", IntWalk_StatusDeflection::IntWalk_StepTooSmall)
		.value("IntWalk_PointConfondu", IntWalk_StatusDeflection::IntWalk_PointConfondu)
		.value("IntWalk_ArretSurPointPrecedent", IntWalk_StatusDeflection::IntWalk_ArretSurPointPrecedent)
		.value("IntWalk_ArretSurPoint", IntWalk_StatusDeflection::IntWalk_ArretSurPoint)
		.value("IntWalk_OK", IntWalk_StatusDeflection::IntWalk_OK)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntWalk_VectorOfWalkingData.hxx
	py::class_<IntWalk_WalkingData, std::unique_ptr<IntWalk_WalkingData, Deleter<IntWalk_WalkingData>>> cls_IntWalk_WalkingData(mod, "IntWalk_WalkingData", "None");
	cls_IntWalk_WalkingData.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntWalk_TheFunctionOfTheInt2S.hxx
	py::class_<IntWalk_TheFunctionOfTheInt2S, std::unique_ptr<IntWalk_TheFunctionOfTheInt2S, Deleter<IntWalk_TheFunctionOfTheInt2S>>, math_FunctionSetWithDerivatives> cls_IntWalk_TheFunctionOfTheInt2S(mod, "IntWalk_TheFunctionOfTheInt2S", "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S1"), py::arg("S2"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("NbVariables", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::NbVariables, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("NbEquations", (Standard_Integer (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::NbEquations, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("Value", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::Value, "None", py::arg("X"), py::arg("F"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("Derivatives", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Derivatives, "None", py::arg("X"), py::arg("D"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("Values", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, math_Vector &, math_Matrix &)) &IntWalk_TheFunctionOfTheInt2S::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("ComputeParameters", (void (IntWalk_TheFunctionOfTheInt2S::*)(const IntImp_ConstIsoparametric, const TColStd_Array1OfReal &, math_Vector &, math_Vector &, math_Vector &, math_Vector &)) &IntWalk_TheFunctionOfTheInt2S::ComputeParameters, "None", py::arg("ChoixIso"), py::arg("Param"), py::arg("UVap"), py::arg("BornInf"), py::arg("BornSup"), py::arg("Tolerance"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("Root", (Standard_Real (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::Root, "returns somme des fi*fi");
	cls_IntWalk_TheFunctionOfTheInt2S.def("Point", (gp_Pnt (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::Point, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheFunctionOfTheInt2S::*)(const math_Vector &, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &IntWalk_TheFunctionOfTheInt2S::IsTangent, "None", py::arg("UVap"), py::arg("Param"), py::arg("BestChoix"));
	cls_IntWalk_TheFunctionOfTheInt2S.def("Direction", (gp_Dir (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::Direction, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS1", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS1, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("DirectionOnS2", (gp_Dir2d (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::DirectionOnS2, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface1", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface1, "None");
	cls_IntWalk_TheFunctionOfTheInt2S.def("AuxillarSurface2", (const opencascade::handle<Adaptor3d_HSurface> & (IntWalk_TheFunctionOfTheInt2S::*)() const ) &IntWalk_TheFunctionOfTheInt2S::AuxillarSurface2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntWalk_TheInt2S.hxx
	py::class_<IntWalk_TheInt2S, std::unique_ptr<IntWalk_TheInt2S, Deleter<IntWalk_TheInt2S>>> cls_IntWalk_TheInt2S(mod, "IntWalk_TheInt2S", "None");
	cls_IntWalk_TheInt2S.def(py::init<const TColStd_Array1OfReal &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Param"), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
	cls_IntWalk_TheInt2S.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("TolTangency"));
	cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is calculated)", py::arg("Param"), py::arg("Rsnld"));
	cls_IntWalk_TheInt2S.def("Perform", (IntImp_ConstIsoparametric (IntWalk_TheInt2S::*)(const TColStd_Array1OfReal &, math_FunctionSetRoot &, const IntImp_ConstIsoparametric)) &IntWalk_TheInt2S::Perform, "returns the best constant isoparametric to find the next intersection's point +stores the solution point (the solution point is found with the close point to intersect the isoparametric with the other patch; the choice of the isoparametic is given by ChoixIso)", py::arg("Param"), py::arg("Rsnld"), py::arg("ChoixIso"));
	cls_IntWalk_TheInt2S.def("IsDone", (Standard_Boolean (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::IsDone, "Returns TRUE if the creation completed without failure.");
	cls_IntWalk_TheInt2S.def("IsEmpty", (Standard_Boolean (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::IsEmpty, "Returns TRUE when there is no solution to the problem.");
	cls_IntWalk_TheInt2S.def("Point", (const IntSurf_PntOn2S & (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::Point, "Returns the intersection point.");
	cls_IntWalk_TheInt2S.def("IsTangent", (Standard_Boolean (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::IsTangent, "Returns True if the surfaces are tangent at the intersection point.");
	cls_IntWalk_TheInt2S.def("Direction", (const gp_Dir & (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::Direction, "Returns the tangent at the intersection line.");
	cls_IntWalk_TheInt2S.def("DirectionOnS1", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::DirectionOnS1, "Returns the tangent at the intersection line in the parametric space of the first surface.");
	cls_IntWalk_TheInt2S.def("DirectionOnS2", (const gp_Dir2d & (IntWalk_TheInt2S::*)() const ) &IntWalk_TheInt2S::DirectionOnS2, "Returns the tangent at the intersection line in the parametric space of the second surface.");
	cls_IntWalk_TheInt2S.def("Function", (IntWalk_TheFunctionOfTheInt2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::Function, "return the math function which is used to compute the intersection");
	cls_IntWalk_TheInt2S.def("ChangePoint", (IntSurf_PntOn2S & (IntWalk_TheInt2S::*)()) &IntWalk_TheInt2S::ChangePoint, "return the intersection point which is enable for changing.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntWalk_PWalking.hxx
	py::class_<IntWalk_PWalking, std::unique_ptr<IntWalk_PWalking, Deleter<IntWalk_PWalking>>> cls_IntWalk_PWalking(mod, "IntWalk_PWalking", "This class implements an algorithm to determine the intersection between 2 parametrized surfaces, marching from a starting point. The intersection line starts and ends on the natural surface's boundaries .");
	cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
	cls_IntWalk_PWalking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Caro1"), py::arg("Caro2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
	cls_IntWalk_PWalking.def("Perform", (void (IntWalk_PWalking::*)(const TColStd_Array1OfReal &)) &IntWalk_PWalking::Perform, "calculate the line of intersection", py::arg("ParDep"));
	cls_IntWalk_PWalking.def("Perform", (void (IntWalk_PWalking::*)(const TColStd_Array1OfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntWalk_PWalking::Perform, "calculate the line of intersection. The regulation of steps is done using min and max values on u and v. (if this data is not presented as in the previous method, the initial steps are calculated starting from min and max uv of faces).", py::arg("ParDep"), py::arg("u1min"), py::arg("v1min"), py::arg("u2min"), py::arg("v2min"), py::arg("u1max"), py::arg("v1max"), py::arg("u2max"), py::arg("v2max"));
	cls_IntWalk_PWalking.def("PerformFirstPoint", (Standard_Boolean (IntWalk_PWalking::*)(const TColStd_Array1OfReal &, IntSurf_PntOn2S &)) &IntWalk_PWalking::PerformFirstPoint, "calculate the first point of a line of intersection", py::arg("ParDep"), py::arg("FirstPoint"));
	cls_IntWalk_PWalking.def("IsDone", (Standard_Boolean (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::IsDone, "Returns true if the calculus was successful.");
	cls_IntWalk_PWalking.def("NbPoints", (Standard_Integer (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::NbPoints, "Returns the number of points of the resulting polyline. An exception is raised if IsDone returns False.");
	cls_IntWalk_PWalking.def("Value", (const IntSurf_PntOn2S & (IntWalk_PWalking::*)(const Standard_Integer) const ) &IntWalk_PWalking::Value, "Returns the point of range Index on the polyline. An exception is raised if IsDone returns False. An exception is raised if Index<=0 or Index>NbPoints.", py::arg("Index"));
	cls_IntWalk_PWalking.def("Line", (const opencascade::handle<IntSurf_LineOn2S> & (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::Line, "None");
	cls_IntWalk_PWalking.def("TangentAtFirst", (Standard_Boolean (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::TangentAtFirst, "Returns True if the surface are tangent at the first point of the line. An exception is raised if IsDone returns False.");
	cls_IntWalk_PWalking.def("TangentAtLast", (Standard_Boolean (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::TangentAtLast, "Returns true if the surface are tangent at the last point of the line. An exception is raised if IsDone returns False.");
	cls_IntWalk_PWalking.def("IsClosed", (Standard_Boolean (IntWalk_PWalking::*)() const ) &IntWalk_PWalking::IsClosed, "Returns True if the line is closed. An exception is raised if IsDone returns False.");
	cls_IntWalk_PWalking.def("TangentAtLine", (const gp_Dir & (IntWalk_PWalking::*)(Standard_Integer &) const ) &IntWalk_PWalking::TangentAtLine, "None", py::arg("Index"));
	cls_IntWalk_PWalking.def("TestDeflection", (IntWalk_StatusDeflection (IntWalk_PWalking::*)(const IntImp_ConstIsoparametric)) &IntWalk_PWalking::TestDeflection, "None", py::arg("ChoixIso"));
	cls_IntWalk_PWalking.def("TestArret", (Standard_Boolean (IntWalk_PWalking::*)(const Standard_Boolean, TColStd_Array1OfReal &, IntImp_ConstIsoparametric &)) &IntWalk_PWalking::TestArret, "None", py::arg("DejaReparti"), py::arg("Param"), py::arg("ChoixIso"));
	cls_IntWalk_PWalking.def("RepartirOuDiviser", (void (IntWalk_PWalking::*)(Standard_Boolean &, IntImp_ConstIsoparametric &, Standard_Boolean &)) &IntWalk_PWalking::RepartirOuDiviser, "None", py::arg("DejaReparti"), py::arg("ChoixIso"), py::arg("Arrive"));
	cls_IntWalk_PWalking.def("AddAPoint", (void (IntWalk_PWalking::*)(opencascade::handle<IntSurf_LineOn2S> &, const IntSurf_PntOn2S &)) &IntWalk_PWalking::AddAPoint, "None", py::arg("line"), py::arg("POn2S"));
	cls_IntWalk_PWalking.def("PutToBoundary", (Standard_Boolean (IntWalk_PWalking::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntWalk_PWalking::PutToBoundary, "None", py::arg("theASurf1"), py::arg("theASurf2"));
	cls_IntWalk_PWalking.def("SeekAdditionalPoints", (Standard_Boolean (IntWalk_PWalking::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer)) &IntWalk_PWalking::SeekAdditionalPoints, "None", py::arg("theASurf1"), py::arg("theASurf2"), py::arg("theMinNbPoints"));
	cls_IntWalk_PWalking.def("MaxStep", (Standard_Real (IntWalk_PWalking::*)(Standard_Integer)) &IntWalk_PWalking::MaxStep, "None", py::arg("theIndex"));

	/* FIXME
	// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\vector
	py::class_<IntWalk_VectorOfWalkingData, std::unique_ptr<IntWalk_VectorOfWalkingData, Deleter<IntWalk_VectorOfWalkingData>>, _Vector_alloc<_Vec_base_types<IntWalk_WalkingData, NCollection_StdAllocator<IntWalk_WalkingData>> >> cls_IntWalk_VectorOfWalkingData(mod, "IntWalk_VectorOfWalkingData", "None");
	cls_IntWalk_VectorOfWalkingData.def(py::init<>());
	cls_IntWalk_VectorOfWalkingData.def(py::init<const NCollection_StdAllocator<IntWalk_WalkingData> &>(), py::arg("_Al"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<std::IntWalk_VectorOfWalkingData::size_type>(), py::arg("_Count"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<std::IntWalk_VectorOfWalkingData::size_type, const std::IntWalk_VectorOfWalkingData::value_type &>(), py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<std::IntWalk_VectorOfWalkingData::size_type, const std::IntWalk_VectorOfWalkingData::value_type &, const NCollection_StdAllocator<IntWalk_WalkingData> &>(), py::arg("_Count"), py::arg("_Val"), py::arg("_Al"));
	cls_IntWalk_VectorOfWalkingData.def(py::init([] (const std::IntWalk_VectorOfWalkingData::_Myt &other) {return new IntWalk_VectorOfWalkingData(other);}), "Copy constructor", py::arg("other"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<const std::IntWalk_VectorOfWalkingData::_Myt &, const NCollection_StdAllocator<IntWalk_WalkingData> &>(), py::arg("_Right"), py::arg("_Al"));
	// FIXME cls_IntWalk_VectorOfWalkingData.def(py::init<std::IntWalk_VectorOfWalkingData::_Myt &&>(), py::arg("_Right"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<std::IntWalk_VectorOfWalkingData::_Myt &&, const NCollection_StdAllocator<IntWalk_WalkingData> &>(), py::arg("_Right"), py::arg("_Al"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<::std::initializer_list<value_type>>(), py::arg("_Ilist"));
	cls_IntWalk_VectorOfWalkingData.def(py::init<::std::initializer_list<value_type>, const NCollection_StdAllocator<IntWalk_WalkingData> &>(), py::arg("_Ilist"), py::arg("_Al"));
	cls_IntWalk_VectorOfWalkingData.def("_Construct_n", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type, const std::IntWalk_VectorOfWalkingData::value_type *)) &IntWalk_VectorOfWalkingData::_Construct_n, "None", py::arg("_Count"), py::arg("_Pval"));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("assign", (std::IntWalk_VectorOfWalkingData::_Myt & (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::_Myt &&)) &IntWalk_VectorOfWalkingData::operator=, py::is_operator(), "None", py::arg("_Right"));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("_Assign_rv", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::_Myt &&, std::true_type)) &IntWalk_VectorOfWalkingData::_Assign_rv, "None", py::arg("_Right"), py::arg(""));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("_Assign_rv", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::_Myt &&, std::false_type)) &IntWalk_VectorOfWalkingData::_Assign_rv, "None", py::arg("_Right"), py::arg(""));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("_Assign_rv", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::_Myt &&)) &IntWalk_VectorOfWalkingData::_Assign_rv, "None", py::arg("_Right"));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("push_back", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::value_type &&)) &IntWalk_VectorOfWalkingData::push_back, "None", py::arg("_Val"));
	// FIXME cls_IntWalk_VectorOfWalkingData.def("insert", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator, IntWalk_WalkingData &&)) &IntWalk_VectorOfWalkingData::insert, "None", py::arg("_Where"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("assign", (std::IntWalk_VectorOfWalkingData::_Myt & (IntWalk_VectorOfWalkingData::*)(::std::initializer_list<value_type>)) &IntWalk_VectorOfWalkingData::operator=, py::is_operator(), "None", py::arg("_Ilist"));
	cls_IntWalk_VectorOfWalkingData.def("assign", (void (IntWalk_VectorOfWalkingData::*)(::std::initializer_list<value_type>)) &IntWalk_VectorOfWalkingData::assign, "None", py::arg("_Ilist"));
	cls_IntWalk_VectorOfWalkingData.def("insert", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator, ::std::initializer_list<value_type>)) &IntWalk_VectorOfWalkingData::insert, "None", py::arg("_Where"), py::arg("_Ilist"));
	cls_IntWalk_VectorOfWalkingData.def("assign", (std::IntWalk_VectorOfWalkingData::_Myt & (IntWalk_VectorOfWalkingData::*)(const std::IntWalk_VectorOfWalkingData::_Myt &)) &IntWalk_VectorOfWalkingData::operator=, py::is_operator(), "None", py::arg("_Right"));
	cls_IntWalk_VectorOfWalkingData.def("reserve", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type)) &IntWalk_VectorOfWalkingData::reserve, "None", py::arg("_Count"));
	cls_IntWalk_VectorOfWalkingData.def("capacity", (std::IntWalk_VectorOfWalkingData::size_type (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::capacity, "None");
	cls_IntWalk_VectorOfWalkingData.def("_Unused_capacity", (std::IntWalk_VectorOfWalkingData::size_type (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::_Unused_capacity, "None");
	cls_IntWalk_VectorOfWalkingData.def("_Has_unused_capacity", (std::IntWalk_VectorOfWalkingData::size_type (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::_Has_unused_capacity, "None");
	cls_IntWalk_VectorOfWalkingData.def("begin", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::begin, "None");
	cls_IntWalk_VectorOfWalkingData.def("begin", (std::IntWalk_VectorOfWalkingData::const_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::begin, "None");
	cls_IntWalk_VectorOfWalkingData.def("end", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::end, "None");
	cls_IntWalk_VectorOfWalkingData.def("end", (std::IntWalk_VectorOfWalkingData::const_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::end, "None");
	cls_IntWalk_VectorOfWalkingData.def("_Make_iter", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator) const ) &IntWalk_VectorOfWalkingData::_Make_iter, "None", py::arg("_Where"));
	cls_IntWalk_VectorOfWalkingData.def("rbegin", (std::IntWalk_VectorOfWalkingData::reverse_iterator (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::rbegin, "None");
	cls_IntWalk_VectorOfWalkingData.def("rbegin", (std::IntWalk_VectorOfWalkingData::const_reverse_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::rbegin, "None");
	cls_IntWalk_VectorOfWalkingData.def("rend", (std::IntWalk_VectorOfWalkingData::reverse_iterator (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::rend, "None");
	cls_IntWalk_VectorOfWalkingData.def("rend", (std::IntWalk_VectorOfWalkingData::const_reverse_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::rend, "None");
	cls_IntWalk_VectorOfWalkingData.def("cbegin", (std::IntWalk_VectorOfWalkingData::const_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::cbegin, "None");
	cls_IntWalk_VectorOfWalkingData.def("cend", (std::IntWalk_VectorOfWalkingData::const_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::cend, "None");
	cls_IntWalk_VectorOfWalkingData.def("crbegin", (std::IntWalk_VectorOfWalkingData::const_reverse_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::crbegin, "None");
	cls_IntWalk_VectorOfWalkingData.def("crend", (std::IntWalk_VectorOfWalkingData::const_reverse_iterator (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::crend, "None");
	cls_IntWalk_VectorOfWalkingData.def("shrink_to_fit", (void (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::shrink_to_fit, "None");
	cls_IntWalk_VectorOfWalkingData.def("resize", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type)) &IntWalk_VectorOfWalkingData::resize, "None", py::arg("_Newsize"));
	cls_IntWalk_VectorOfWalkingData.def("resize", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type, const std::IntWalk_VectorOfWalkingData::value_type &)) &IntWalk_VectorOfWalkingData::resize, "None", py::arg("_Newsize"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("size", (std::IntWalk_VectorOfWalkingData::size_type (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::size, "None");
	cls_IntWalk_VectorOfWalkingData.def("max_size", (std::IntWalk_VectorOfWalkingData::size_type (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::max_size, "None");
	cls_IntWalk_VectorOfWalkingData.def("empty", (bool (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::empty, "None");
	cls_IntWalk_VectorOfWalkingData.def("get_allocator", (NCollection_StdAllocator<IntWalk_WalkingData> (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::get_allocator, "None");
	cls_IntWalk_VectorOfWalkingData.def("at", (std::IntWalk_VectorOfWalkingData::const_reference (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type) const ) &IntWalk_VectorOfWalkingData::at, "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfWalkingData.def("at", (std::IntWalk_VectorOfWalkingData::reference (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type)) &IntWalk_VectorOfWalkingData::at, "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfWalkingData.def("__getitem__", (std::IntWalk_VectorOfWalkingData::const_reference (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type) const ) &IntWalk_VectorOfWalkingData::operator[], py::is_operator(), "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfWalkingData.def("__getitem__", (std::IntWalk_VectorOfWalkingData::reference (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type)) &IntWalk_VectorOfWalkingData::operator[], py::is_operator(), "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfWalkingData.def("data", (IntWalk_WalkingData * (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::data, "None");
	cls_IntWalk_VectorOfWalkingData.def("data", (const IntWalk_WalkingData * (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::data, "None");
	cls_IntWalk_VectorOfWalkingData.def("front", (std::IntWalk_VectorOfWalkingData::reference (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::front, "None");
	cls_IntWalk_VectorOfWalkingData.def("front", (std::IntWalk_VectorOfWalkingData::const_reference (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::front, "None");
	cls_IntWalk_VectorOfWalkingData.def("back", (std::IntWalk_VectorOfWalkingData::reference (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::back, "None");
	cls_IntWalk_VectorOfWalkingData.def("back", (std::IntWalk_VectorOfWalkingData::const_reference (IntWalk_VectorOfWalkingData::*)() const ) &IntWalk_VectorOfWalkingData::back, "None");
	cls_IntWalk_VectorOfWalkingData.def("push_back", (void (IntWalk_VectorOfWalkingData::*)(const std::IntWalk_VectorOfWalkingData::value_type &)) &IntWalk_VectorOfWalkingData::push_back, "None", py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("pop_back", (void (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::pop_back, "None");
	cls_IntWalk_VectorOfWalkingData.def("assign", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type, const std::IntWalk_VectorOfWalkingData::value_type &)) &IntWalk_VectorOfWalkingData::assign, "None", py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("insert", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator, const IntWalk_WalkingData &)) &IntWalk_VectorOfWalkingData::insert, "None", py::arg("_Where"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("insert", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator, std::IntWalk_VectorOfWalkingData::size_type, const IntWalk_WalkingData &)) &IntWalk_VectorOfWalkingData::insert, "None", py::arg("_Where"), py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfWalkingData.def("erase", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator)) &IntWalk_VectorOfWalkingData::erase, "None", py::arg("_Where"));
	cls_IntWalk_VectorOfWalkingData.def("erase", (std::IntWalk_VectorOfWalkingData::iterator (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::const_iterator, std::IntWalk_VectorOfWalkingData::const_iterator)) &IntWalk_VectorOfWalkingData::erase, "None", py::arg("_First_arg"), py::arg("_Last_arg"));
	cls_IntWalk_VectorOfWalkingData.def("_Pop_back_n", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::size_type)) &IntWalk_VectorOfWalkingData::_Pop_back_n, "None", py::arg("_Count"));
	cls_IntWalk_VectorOfWalkingData.def("clear", (void (IntWalk_VectorOfWalkingData::*)()) &IntWalk_VectorOfWalkingData::clear, "None");
	cls_IntWalk_VectorOfWalkingData.def("swap", (void (IntWalk_VectorOfWalkingData::*)(std::IntWalk_VectorOfWalkingData::_Myt &)) &IntWalk_VectorOfWalkingData::swap, "None", py::arg("_Right"));
	cls_IntWalk_VectorOfWalkingData.def("__iter__", [](const IntWalk_VectorOfWalkingData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	*/

	/* FIXME
	// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\vector
	py::class_<IntWalk_VectorOfInteger, std::unique_ptr<IntWalk_VectorOfInteger, Deleter<IntWalk_VectorOfInteger>>, _Vector_alloc<_Vec_base_types<Standard_Integer, NCollection_StdAllocator<Standard_Integer>> >> cls_IntWalk_VectorOfInteger(mod, "IntWalk_VectorOfInteger", "None");
	cls_IntWalk_VectorOfInteger.def(py::init<>());
	cls_IntWalk_VectorOfInteger.def(py::init<const NCollection_StdAllocator<Standard_Integer> &>(), py::arg("_Al"));
	cls_IntWalk_VectorOfInteger.def(py::init<std::IntWalk_VectorOfInteger::size_type>(), py::arg("_Count"));
	cls_IntWalk_VectorOfInteger.def(py::init<std::IntWalk_VectorOfInteger::size_type, const std::IntWalk_VectorOfInteger::value_type &>(), py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def(py::init<std::IntWalk_VectorOfInteger::size_type, const std::IntWalk_VectorOfInteger::value_type &, const NCollection_StdAllocator<Standard_Integer> &>(), py::arg("_Count"), py::arg("_Val"), py::arg("_Al"));
	cls_IntWalk_VectorOfInteger.def(py::init([] (const std::IntWalk_VectorOfInteger::_Myt &other) {return new IntWalk_VectorOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_IntWalk_VectorOfInteger.def(py::init<const std::IntWalk_VectorOfInteger::_Myt &, const NCollection_StdAllocator<Standard_Integer> &>(), py::arg("_Right"), py::arg("_Al"));
	// FIXME cls_IntWalk_VectorOfInteger.def(py::init<std::IntWalk_VectorOfInteger::_Myt &&>(), py::arg("_Right"));
	cls_IntWalk_VectorOfInteger.def(py::init<std::IntWalk_VectorOfInteger::_Myt &&, const NCollection_StdAllocator<Standard_Integer> &>(), py::arg("_Right"), py::arg("_Al"));
	cls_IntWalk_VectorOfInteger.def(py::init<::std::initializer_list<value_type>>(), py::arg("_Ilist"));
	cls_IntWalk_VectorOfInteger.def(py::init<::std::initializer_list<value_type>, const NCollection_StdAllocator<Standard_Integer> &>(), py::arg("_Ilist"), py::arg("_Al"));
	cls_IntWalk_VectorOfInteger.def("_Construct_n", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type, const std::IntWalk_VectorOfInteger::value_type *)) &IntWalk_VectorOfInteger::_Construct_n, "None", py::arg("_Count"), py::arg("_Pval"));
	// FIXME cls_IntWalk_VectorOfInteger.def("assign", (std::IntWalk_VectorOfInteger::_Myt & (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::_Myt &&)) &IntWalk_VectorOfInteger::operator=, py::is_operator(), "None", py::arg("_Right"));
	// FIXME cls_IntWalk_VectorOfInteger.def("_Assign_rv", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::_Myt &&, std::true_type)) &IntWalk_VectorOfInteger::_Assign_rv, "None", py::arg("_Right"), py::arg(""));
	// FIXME cls_IntWalk_VectorOfInteger.def("_Assign_rv", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::_Myt &&, std::false_type)) &IntWalk_VectorOfInteger::_Assign_rv, "None", py::arg("_Right"), py::arg(""));
	// FIXME cls_IntWalk_VectorOfInteger.def("_Assign_rv", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::_Myt &&)) &IntWalk_VectorOfInteger::_Assign_rv, "None", py::arg("_Right"));
	// FIXME cls_IntWalk_VectorOfInteger.def("push_back", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::value_type &&)) &IntWalk_VectorOfInteger::push_back, "None", py::arg("_Val"));
	// FIXME cls_IntWalk_VectorOfInteger.def("insert", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator, Standard_Integer &&)) &IntWalk_VectorOfInteger::insert, "None", py::arg("_Where"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("assign", (std::IntWalk_VectorOfInteger::_Myt & (IntWalk_VectorOfInteger::*)(::std::initializer_list<value_type>)) &IntWalk_VectorOfInteger::operator=, py::is_operator(), "None", py::arg("_Ilist"));
	cls_IntWalk_VectorOfInteger.def("assign", (void (IntWalk_VectorOfInteger::*)(::std::initializer_list<value_type>)) &IntWalk_VectorOfInteger::assign, "None", py::arg("_Ilist"));
	cls_IntWalk_VectorOfInteger.def("insert", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator, ::std::initializer_list<value_type>)) &IntWalk_VectorOfInteger::insert, "None", py::arg("_Where"), py::arg("_Ilist"));
	cls_IntWalk_VectorOfInteger.def("assign", (std::IntWalk_VectorOfInteger::_Myt & (IntWalk_VectorOfInteger::*)(const std::IntWalk_VectorOfInteger::_Myt &)) &IntWalk_VectorOfInteger::operator=, py::is_operator(), "None", py::arg("_Right"));
	cls_IntWalk_VectorOfInteger.def("reserve", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type)) &IntWalk_VectorOfInteger::reserve, "None", py::arg("_Count"));
	cls_IntWalk_VectorOfInteger.def("capacity", (std::IntWalk_VectorOfInteger::size_type (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::capacity, "None");
	cls_IntWalk_VectorOfInteger.def("_Unused_capacity", (std::IntWalk_VectorOfInteger::size_type (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::_Unused_capacity, "None");
	cls_IntWalk_VectorOfInteger.def("_Has_unused_capacity", (std::IntWalk_VectorOfInteger::size_type (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::_Has_unused_capacity, "None");
	cls_IntWalk_VectorOfInteger.def("begin", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::begin, "None");
	cls_IntWalk_VectorOfInteger.def("begin", (std::IntWalk_VectorOfInteger::const_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::begin, "None");
	cls_IntWalk_VectorOfInteger.def("end", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::end, "None");
	cls_IntWalk_VectorOfInteger.def("end", (std::IntWalk_VectorOfInteger::const_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::end, "None");
	cls_IntWalk_VectorOfInteger.def("_Make_iter", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator) const ) &IntWalk_VectorOfInteger::_Make_iter, "None", py::arg("_Where"));
	cls_IntWalk_VectorOfInteger.def("rbegin", (std::IntWalk_VectorOfInteger::reverse_iterator (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::rbegin, "None");
	cls_IntWalk_VectorOfInteger.def("rbegin", (std::IntWalk_VectorOfInteger::const_reverse_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::rbegin, "None");
	cls_IntWalk_VectorOfInteger.def("rend", (std::IntWalk_VectorOfInteger::reverse_iterator (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::rend, "None");
	cls_IntWalk_VectorOfInteger.def("rend", (std::IntWalk_VectorOfInteger::const_reverse_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::rend, "None");
	cls_IntWalk_VectorOfInteger.def("cbegin", (std::IntWalk_VectorOfInteger::const_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::cbegin, "None");
	cls_IntWalk_VectorOfInteger.def("cend", (std::IntWalk_VectorOfInteger::const_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::cend, "None");
	cls_IntWalk_VectorOfInteger.def("crbegin", (std::IntWalk_VectorOfInteger::const_reverse_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::crbegin, "None");
	cls_IntWalk_VectorOfInteger.def("crend", (std::IntWalk_VectorOfInteger::const_reverse_iterator (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::crend, "None");
	cls_IntWalk_VectorOfInteger.def("shrink_to_fit", (void (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::shrink_to_fit, "None");
	cls_IntWalk_VectorOfInteger.def("resize", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type)) &IntWalk_VectorOfInteger::resize, "None", py::arg("_Newsize"));
	cls_IntWalk_VectorOfInteger.def("resize", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type, const std::IntWalk_VectorOfInteger::value_type &)) &IntWalk_VectorOfInteger::resize, "None", py::arg("_Newsize"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("size", (std::IntWalk_VectorOfInteger::size_type (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::size, "None");
	cls_IntWalk_VectorOfInteger.def("max_size", (std::IntWalk_VectorOfInteger::size_type (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::max_size, "None");
	cls_IntWalk_VectorOfInteger.def("empty", (bool (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::empty, "None");
	cls_IntWalk_VectorOfInteger.def("get_allocator", (NCollection_StdAllocator<Standard_Integer> (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::get_allocator, "None");
	cls_IntWalk_VectorOfInteger.def("at", (std::IntWalk_VectorOfInteger::const_reference (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type) const ) &IntWalk_VectorOfInteger::at, "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfInteger.def("at", (std::IntWalk_VectorOfInteger::reference (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type)) &IntWalk_VectorOfInteger::at, "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfInteger.def("__getitem__", (std::IntWalk_VectorOfInteger::const_reference (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type) const ) &IntWalk_VectorOfInteger::operator[], py::is_operator(), "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfInteger.def("__getitem__", (std::IntWalk_VectorOfInteger::reference (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type)) &IntWalk_VectorOfInteger::operator[], py::is_operator(), "None", py::arg("_Pos"));
	cls_IntWalk_VectorOfInteger.def("data", (Standard_Integer * (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::data, "None");
	cls_IntWalk_VectorOfInteger.def("data", (const Standard_Integer * (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::data, "None");
	cls_IntWalk_VectorOfInteger.def("front", (std::IntWalk_VectorOfInteger::reference (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::front, "None");
	cls_IntWalk_VectorOfInteger.def("front", (std::IntWalk_VectorOfInteger::const_reference (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::front, "None");
	cls_IntWalk_VectorOfInteger.def("back", (std::IntWalk_VectorOfInteger::reference (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::back, "None");
	cls_IntWalk_VectorOfInteger.def("back", (std::IntWalk_VectorOfInteger::const_reference (IntWalk_VectorOfInteger::*)() const ) &IntWalk_VectorOfInteger::back, "None");
	cls_IntWalk_VectorOfInteger.def("push_back", (void (IntWalk_VectorOfInteger::*)(const std::IntWalk_VectorOfInteger::value_type &)) &IntWalk_VectorOfInteger::push_back, "None", py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("pop_back", (void (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::pop_back, "None");
	cls_IntWalk_VectorOfInteger.def("assign", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type, const std::IntWalk_VectorOfInteger::value_type &)) &IntWalk_VectorOfInteger::assign, "None", py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("insert", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator, const Standard_Integer &)) &IntWalk_VectorOfInteger::insert, "None", py::arg("_Where"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("insert", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator, std::IntWalk_VectorOfInteger::size_type, const Standard_Integer &)) &IntWalk_VectorOfInteger::insert, "None", py::arg("_Where"), py::arg("_Count"), py::arg("_Val"));
	cls_IntWalk_VectorOfInteger.def("erase", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator)) &IntWalk_VectorOfInteger::erase, "None", py::arg("_Where"));
	cls_IntWalk_VectorOfInteger.def("erase", (std::IntWalk_VectorOfInteger::iterator (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::const_iterator, std::IntWalk_VectorOfInteger::const_iterator)) &IntWalk_VectorOfInteger::erase, "None", py::arg("_First_arg"), py::arg("_Last_arg"));
	cls_IntWalk_VectorOfInteger.def("_Pop_back_n", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::size_type)) &IntWalk_VectorOfInteger::_Pop_back_n, "None", py::arg("_Count"));
	cls_IntWalk_VectorOfInteger.def("clear", (void (IntWalk_VectorOfInteger::*)()) &IntWalk_VectorOfInteger::clear, "None");
	cls_IntWalk_VectorOfInteger.def("swap", (void (IntWalk_VectorOfInteger::*)(std::IntWalk_VectorOfInteger::_Myt &)) &IntWalk_VectorOfInteger::swap, "None", py::arg("_Right"));
	cls_IntWalk_VectorOfInteger.def("__iter__", [](const IntWalk_VectorOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	*/


}
