#ifndef ASIO_WIN_DETAIL_BASE_FROM_COMPLETION_COND_HPP
#define ASIO_WIN_DETAIL_BASE_FROM_COMPLETION_COND_HPP

#include <config.hpp>

namespace asio_win
{
    namespace detail
    {
        template<typename CompletionCondition>
        class base_from_completion_cond
        {
        protected:
            explicit base_from_completion_cond(CompletionCondition cond)
            :completion_cond_(cond)
            {

            }

            std::size_t check_for_completion(const asio_win::error_code& ec, std::size_t total_transferred)
            {
                return detail::adapt_completion_condition_result(completion_cond_(ec, total_tranferred));
            }

        private:

            CompletionCondition completion_cond_;
        };

        template<>
        class base_from_completion_cond<tranfer_all_t>
        {
        protected:
            explicit base_from_completion_cond(tranfer_all_t){}

            static std::size_t check_for_completion(const asio_win::error_code& ec, std::size_t total_transferred)
            {
                return transfer_all_t()(ec, total_tranferred);
            }
        };
    }
}

#endif // ASIO_WIN_DETAIL_BASE_FROM_COMPLETION_COND_HPP
