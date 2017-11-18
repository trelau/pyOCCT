#ifndef __BOPCol_Templates_Header__
#define __BOPCol_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <BOPCol_Parallel.hxx>
#include <ApproxInt_KnotTools.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <BOPCol_NCVector.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
template <typename TypeFunctor, typename TypeSolverVector>
void bind_BOPCol_Cnt(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
	py::class_<BOPCol_Cnt<TypeFunctor, TypeSolverVector>, std::unique_ptr<BOPCol_Cnt<TypeFunctor, TypeSolverVector>, Deleter<BOPCol_Cnt<TypeFunctor, TypeSolverVector>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def_static("Perform_", (void (*)(const Standard_Boolean, TypeSolverVector &)) &BOPCol_Cnt<TypeFunctor, TypeSolverVector>::Perform, "None", py::arg("isRunParallel"), py::arg("theSolverVector"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
template <typename TypeFunctor, typename TypeSolverVector, typename TypeContext>
void bind_BOPCol_ContextCnt(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
	py::class_<BOPCol_ContextCnt<TypeFunctor, TypeSolverVector, TypeContext>, std::unique_ptr<BOPCol_ContextCnt<TypeFunctor, TypeSolverVector, TypeContext>, Deleter<BOPCol_ContextCnt<TypeFunctor, TypeSolverVector, TypeContext>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def_static("Perform_", (void (*)(const Standard_Boolean, TypeSolverVector &, TypeContext &)) &BOPCol_ContextCnt<TypeFunctor, TypeSolverVector, TypeContext>::Perform, "None", py::arg("isRunParallel"), py::arg("theSolverVector"), py::arg("theContext"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
template <typename TypeSolver, typename TypeSolverVector, typename TypeContext, typename TN>
void bind_BOPCol_ContextFunctor(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
	py::class_<BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>, std::unique_ptr<BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>, Deleter<BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<TypeSolverVector &>(), py::arg("theVector"));
	cls.def("SetContext", (void (BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)(TypeContext &)) &BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::SetContext, "Binds main thread context", py::arg("theContext"));
	cls.def("GetThreadContext", (TypeContext & (BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)() const ) &BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::GetThreadContext, "Returns current thread context");
	cls.def("__call__", (void (BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::*)(const Standard_Integer) const ) &BOPCol_ContextFunctor<TypeSolver, TypeSolverVector, TypeContext, TN>::operator(), py::is_operator(), "Defines functor interface", py::arg("theIndex"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
template <typename TypeSolver, typename TypeSolverVector>
void bind_BOPCol_Functor(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Parallel.hxx
	py::class_<BOPCol_Functor<TypeSolver, TypeSolverVector>, std::unique_ptr<BOPCol_Functor<TypeSolver, TypeSolverVector>, Deleter<BOPCol_Functor<TypeSolver, TypeSolverVector>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<TypeSolverVector &>(), py::arg("theSolverVec"));
	cls.def("__call__", (void (BOPCol_Functor<TypeSolver, TypeSolverVector>::*)(const Standard_Integer) const ) &BOPCol_Functor<TypeSolver, TypeSolverVector>::operator(), py::is_operator(), "Defines functor interface.", py::arg("theIndex"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
template <typename Type>
void bind_BOPCol_NCVector(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_NCVector.hxx
	py::class_<BOPCol_NCVector<Type>, std::unique_ptr<BOPCol_NCVector<Type>, Deleter<BOPCol_NCVector<Type>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));
	cls.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theIncrement"), py::arg("theAlloc"));
	cls.def("Append1", (Type & (BOPCol_NCVector<Type>::*)()) &BOPCol_NCVector<Type>::Append1, "None");
	cls.def("Extent", (Standard_Integer (BOPCol_NCVector<Type>::*)() const ) &BOPCol_NCVector<Type>::Extent, "None");

};

#endif